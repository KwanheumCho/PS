#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
// 프로그래머스

int N;

struct _type{
    pair<int, int> A_;
    pair<int, int> B_;
    int t;
    int p;
};

bool chk(pair<int, int> X){
    if(X.first ==N && X.second == N) return true;
    else return false;
}

bool in_map(int r, int c){
    if(r>=1 && r<=N && c>=1 && c<=N) return true;
    else return false;
}
int find_dir(pair<int, int> A, pair<int, int> B){
    int dx = B.second - A.second; // col의 방향
    int dy = B.first - A.first; // row의 방향
    if(dx==1){
        return 0;
    }
    else if(dy==1){
        return 1;
    }
    else if(dx==-1){
        return 2;
    }
    else if(dy==-1){
        return 3;
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    //로봇의 움직임 : 상하좌우, 왼쪽축을 기준으로 회전, 오른쪽축을 기준으로 회전
    //회전은 축 기준으로 대각선이 0이어야한다.
    vector< pair<int, int> > robot;
    robot.push_back({1,1});
    robot.push_back({1,2});
    bool visited[2][101][101] = {false, };
    visited[0][1][1] = true;
    visited[0][1][2] = true;
    queue< _type >s;
    s.push({robot[0],robot[1], 0, 0});
    //cout << s.front().A.first << endl;
    
    int time;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    int ddr[4] = {-1, 1, 1, -1 }; //대각선체크용
    int ddc[4] = {1, 1, -1, -1};
    int _ddr[4] = {1, 1, -1 ,-1};
    int _ddc[4] = {1, -1, -1 ,1};
    while(!s.empty()){
        
        pair<int, int> A, B;
        A = s.front().A_;
        B = s.front().B_;
        time = s.front().t;
        int p = s.front().p;
        
        s.pop();
        if(chk(A) || chk(B)){
            answer = time;
            break;
        }
        for(int i=0; i<4; i++){//상하좌우 이동
            int a_nr = A.first + dr[i];
            int a_nc = A.second + dc[i];
            int b_nr = B.first + dr[i];
            int b_nc = B.second + dc[i];
            if(in_map(a_nr,a_nc) && in_map(b_nr,b_nc)){
                if(board[a_nr-1][a_nc-1]==0 && board[b_nr-1][b_nc-1]==0 && (!visited[p][a_nr][a_nc]||!visited[p][b_nr][b_nc])){
                    visited[p][a_nr][a_nc] = true;
                    visited[p][b_nr][b_nc] = true;
                    s.push({{a_nr,a_nc},{b_nr,b_nc}, time+1, p});
                }
            }
        }
        
        //A점 기준으로해서 회전
        int dir = find_dir(A, B); //A->B 현재방향
        for(int i=1; i<=3; i+=2){
            int n_dir = (dir+i)%4;
            int b_nr = A.first + dr[n_dir];
            int b_nc = A.second + dc[n_dir];
            if(in_map(b_nr,b_nc)){
                int cross_r, cross_c;
                if(i==1){
                    cross_r = A.first + ddr[n_dir];
                    cross_c = A.second + ddc[n_dir];
                }
                else if(i==3){
                    cross_r = A.first + _ddr[n_dir];
                    cross_c = A.second + _ddc[n_dir];
                }
                
                int new_p = (p+1)%2;
                if(in_map(cross_r, cross_c) && board[cross_r-1][cross_c-1]==0 && board[b_nr-1][b_nc-1]==0 &&  (!visited[new_p][b_nr][b_nc])){
                    visited[new_p][b_nr][b_nc] = true;
                    s.push({A, {b_nr,b_nc},time+1, new_p});
                }
            }
        }
        
        
        //B점기준으로 회전
        dir = find_dir(B, A); // B->A 현재방향
        for(int i=1; i<=3; i+=2){
            int n_dir = (dir+i)%4;
            int a_nr = B.first + dr[n_dir];
            int a_nc = B.second + dc[n_dir];
            if(in_map(a_nr,a_nc)){
                int cross_r, cross_c;
                if(i==1){
                    cross_r = B.first + ddr[n_dir];
                    cross_c = B.second + ddc[n_dir];
                }
                else if(i==3){
                    cross_r = B.first + _ddr[n_dir];
                    cross_c = B.second + _ddc[n_dir];
                }
                
                int new_p = (p+1)%2;
                if(in_map(cross_r, cross_c) && board[cross_r-1][cross_c-1]==0 && board[a_nr-1][a_nc-1]==0 && (!visited[new_p][a_nr][a_nc])){
                    visited[new_p][a_nr][a_nc] = true;
                    s.push({{a_nr,a_nc}, B, time+1, new_p});
                }
            }
        }
        
    }//while
    
    return answer;
}