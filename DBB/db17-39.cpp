#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define INF 1e9
int main(void){
    int t;
    cin >> t;
    for(int ii=0; ii<t; ii++){
        int n;
        cin >> n;
        int arr[126][126];
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                cin >> arr[r][c];
            }
        }
        
        int dp[126][126];
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                dp[r][c] = INF;
            }
        }
        dp[0][0] = arr[0][0];
        int dr[4] = { 0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        priority_queue< pair<int, pair<int, int> > > pq;
        pq.push({ -dp[0][0], {0,0} }); // -붙여줘서 오름차순으로 만들어줌
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int dist = -pq.top().first;
            pq.pop();
            if( dp[row][col] < dist ) continue; //이전에 이미 방문해서 최소값 존재.
            for(int i=0; i<4; i++){
                int nr = row+dr[i];
                int nc = col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    if( dp[nr][nc] > dist + arr[nr][nc]){
                        dp[nr][nc] = dist+arr[nr][nc];
                        pq.push( {-dp[nr][nc], {nr, nc}} );
                    }
                }
            }
        }
        /*
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        cout << dp[n-1][n-1] << endl;

    }

}