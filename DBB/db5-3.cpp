#include <iostream>
#include <queue>
using namespace std;

int map_[100][100];
bool chk_[100][100] = {false, };
int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int answer = 0;

void func_(int row, int col){

    queue<pair<int, int> > q;
    chk_[row][col] = true;
    q.push({row, col});
    while(!q.empty()){
        row = q.front().first;
        col = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
        int nc = col+dx[i];
        int nr = row+dy[i];
        if(nr>=0 && nr<N && nc>=0 && nc <M){
            if(map_[nr][nc]==0 && chk_[nr][nc]==false){
                chk_[nr][nc] = true;
                q.push({nr,nc});
            }
        }
    }
    }
    answer++;
    return;
}

int main(void){
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map_[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map_[i][j] == 0 && chk_[i][j]==false){
                func_(i, j);
            }
        }
    }
    cout << answer << endl;

}