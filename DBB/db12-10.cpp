//프로그래머스
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > rotate_func(vector<vector<int> > key){//시계방향 회전
    int size = key.size();
    vector<vector<int > > tmp(size, vector<int>(size) );
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            tmp[j][size-i-1] = key[i][j];
        }
    }
    return tmp;
}



bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    // key의 길이를 N+(M-1)+(M-1)로 늘리고
    // 시작점 : (0,0) ~ (N+M-1 , 0) (0, N+M-1)
    bool answer = false;
    int N = lock.size();
    int M = key.size();
    int hom_number = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(lock[i][j]==0) hom_number++;
        }
    }
    int new_size = N+2*(M-1);
    vector<vector<int > > new_lock(new_size, vector<int>(new_size));
    for(int i=M-1; i<N+M-1; i++){
        for(int j=M-1; j<N+M-1; j++){
            new_lock[i][j] = lock[i-(M-1)][j-(M-1)];
        }
    }
    //0~ < N+M-1
    // lock의 위치 : M-1 ~ <= N+M-2
    for(int rotate=0; rotate<4; rotate++){
        
        for(int i=0; i<N+M-1; i++){
            for(int j=0; j<N+M-1; j++){
                bool dolgi_chk = false;
                int cnt = 0;
                for(int ii=0; ii<M; ii++){
                    for(int jj=0; jj<M; jj++){
                        int row = i + ii;
                        int col = j + jj;
                        if(row>=M-1 && row <=N+M-2 && col>=M-1 && col<=N+M-2){
                            if(key[ii][jj]==1 && new_lock[row][col]==1){
                                dolgi_chk = true;
                                break;//둘다 돌기
                            }
                            else if(key[ii][jj]==1&& new_lock[row][col]==0){
                                cnt++;
                            }//둘다 00 이면 cnt를 안채워서 어차피 나중에 상관X
                            // key0 lock1인 경우는 애초에 hom number체크에서 안세어서 상관X
                        }
                    }
                    if(dolgi_chk) break;
                    if(ii==M-1 && cnt==hom_number){
                        answer=true;
                        return answer;
                    }
                }
            }//new_lock for문
        }//new_lock for문
        key = rotate_func(key);
    }
    
    
    
    return answer;
}