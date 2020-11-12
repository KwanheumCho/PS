#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
int map_[1001][1001];
bool chk_[1001][1001][2] = {false,}; // 한번만 깰수 있으니까 마지막 차원:2
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; //북동남서 순서


int func_(int r, int c){
    queue< pair< pair<int, int> , pair<int, int> > > q;
    q.push( make_pair(make_pair(r,c) , make_pair(0, 1)));
    chk_[r][c][0] = true;
    while(!q.empty()){
        r = q.front().first.first;
        c = q.front().first.second;
        int wall = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        if(r==N && c==M){
            return cnt;
        }
        for(int i=0; i<4; i++){
            int nr = r + dy[i];
            int nc = c + dx[i];
            if(nr>=1 && nr<=N && nc>=1 && nc<=M){
                if(wall==0 && !chk_[nr][nc][wall]){
                    if(map_[nr][nc] ==0 ) {
                        chk_[nr][nc][wall] = true;
                        q.push( make_pair(make_pair(nr,nc) , make_pair(wall, cnt+1)));
                    }
                    else  {//벽을 깨는 부분!
                        chk_[nr][nc][wall] = true;
                        q.push( make_pair(make_pair(nr,nc) , make_pair(wall+1, cnt+1)));
                    }
                }
                else if(wall==1 &&!chk_[nr][nc][wall]) {
                    if(map_[nr][nc] ==0 ) {
                        chk_[nr][nc][wall] = true;
                        q.push( make_pair(make_pair(nr,nc) , make_pair(wall, cnt+1)));
                    }
                }
            }
        }//for
    }//while
    return -1;
}

int main(void){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        string x;
        cin >> x;
        for(int j=0; j<x.size(); j++){
            map_[i][j+1] = int(x[j]-'0');
        }
    }
    cout << func_(1,1) << endl;
    //불가능하면 -1
    return 0;
}