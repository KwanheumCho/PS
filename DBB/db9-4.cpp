#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    int graph[101][101];
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(i==j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    for(int p=1; p<= n; p++){
        for(int q=1; q<=n; q++){
            for(int r=1; r<=n; r++){
                graph[q][r] = min(graph[q][r], graph[q][p] + graph[p][r]);
            }
        }
    }

    int x, k;
    cin >> x >> k;
    int answer = 0;
    if(graph[1][k]==INF || graph[k][x] == INF) cout << -1<< endl;
    else{
        answer = graph[1][k] + graph[k][x];
        cout << answer << endl;
    }

    //도착할수없다면 -1
    return 0;
}