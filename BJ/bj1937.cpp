#include <iostream>
#include <algorithm>
using namespace std;
int N;
int map_[501][501];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int dp_[501][501];
int func_(int r, int c){
    // r , c 에서의 팬더가 살 수 있는 max 날짜를 반환.
    if(dp_[r][c]!=1) return dp_[r][c];

    int bamboo = map_[r][c];
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >=1 && nr<=N && nc>=1 && nc<=N){
            int nbamboo = map_[nr][nc];
            if(bamboo < nbamboo){
                dp_[r][c] = max(dp_[r][c], func_(nr, nc)+1 );
            }
        }
    }
    return dp_[r][c];
}


int main(void){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map_[i][j];
            dp_[i][j] = 1;
        }
    }
    int answer = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            answer = max(answer, func_(i, j));
        }
    }
    cout << answer << endl;

    return 0;
}