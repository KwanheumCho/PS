#include <string>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    // A B
    int arr[n+1][n+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j] = INF;
        }
    }
    for(int i=0; i<results.size(); i++){
        int from = results[i][0];
        int to = results[i][1];
        arr[from][to] = 1;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]); // INF보다 작으면 가는길이 존재
            }
        }
    }
    for(int i=1; i<=n; i++){
        int cnt =0;
        //i로 가는길 , i에서 가는길 합쳐서 n-1이어야 가능!
        for(int j=1; j<=n; j++){
            if(arr[i][j] < INF || arr[j][i] < INF) cnt++;
        }
        if(cnt == n-1) answer++;
    }
    return answer;
}