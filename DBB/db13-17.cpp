#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map_[201][201];

int main(void){
    int N, K , S ,X, Y; //X는 행 , Y는 열
    cin >> N >> K;
    vector< pair<int, pair<int, int> > > v;
    int x;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){  
            cin >> x;
            map_[i][j] = x;
            if(x!=0){
                v.push_back({x, {i,j}});
            }
        }
    }
    cin >> S >> X >> Y;
    //
    sort(v.begin(), v.end());
    queue< pair<int, pair<int, int> > > q;
    for(int i=0; i<v.size(); i++){
        q.push(v[i]);
    }
    //
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    int time = 0;
    while(time < S){
        int size = q.size();
        //cout << "s: " << size << endl;
        for(int i=0; i<size; i++){
            int virus_number = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int j=0; j<4; j++){
                int nr = row + dr[j];
                int nc = col + dc[j];
                if(nr>=1 && nr<=N && nc>=1 && nc<=N){
                    if(map_[nr][nc]==0) {
                        map_[nr][nc]=virus_number;
                        q.push({virus_number, {nr, nc}});
                    }
                }
            }
        }
        time++;
    }
    if(map_[X][Y] != 0) cout << map_[X][Y] << endl;
    else cout << 0 << endl;
    return 0;
}