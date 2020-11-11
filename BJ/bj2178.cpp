#include <iostream>
#include <string>
#include <queue>
//#include <utility>
using namespace std;
int N, M;
int map_[101][101];
bool chk_[101][101] = {false,};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int func(int r, int c, int cnt){
    chk_[r][c] = true;
    queue< pair < pair<int, int>, int > > q;
    q.push( make_pair( make_pair(r,c) , cnt) );
    while(!q.empty()){
        r = q.front().first.first;
        c = q.front().first.second;
        cnt = q.front().second;
        q.pop();
        //chk_[r][c] = true;
        if(r==N-1 && c==M-1){
            return cnt;
        }
        for(int i=0; i<4; i++){
            int nr = r + dy[i];
            int nc = c + dx[i];
            if(nr>=0 && nr<N && nc>=0 && nc<M){
                if(map_[nr][nc]==1 && chk_[nr][nc] ==false){
                    chk_[nr][nc] = true;
                    //메모리 초과 문제가 생기는 이유였다!!!
                    //큐에 넣을 때, 이 다음에 방문을 무조건 해야한다는 개념이니까
                    //chk를 true로 바꾸고 큐에 넣어야함.
                    //그렇지 않고 큐에서 뺄 때 chk를 바꾸게 되면 중복케이스 발생!
                    q.push( make_pair( make_pair(nr,nc), cnt+1));
                }
            }
        }

    }
}


int main(void){
    cin >> N >> M;
    // n is row , m is column
    for(int i=0; i<N; i++){
        string x;
        cin >> x;
        for(int j=0; j<x.size(); j++){
            map_[i][j] = int(x[j] -'0');
        }
    }
    cout << func(0, 0, 1) << endl;
    //0,0에서 시작해서 N-1,M-1까지 가야돼
    return 0;
}