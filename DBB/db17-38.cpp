#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define INF 1e9
int main(void){
    int n, m;
    cin >> n >> m;
    int arr[501][501];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        int small =0;
        int big = 0;
        for(int j=1; j<=n; j++){
            if(arr[i][j]>0 && arr[i][j]<INF) big++;
            if(arr[j][i]>0 && arr[j][i]<INF) small++;
        }
        if(big+small == n-1) cnt++;
    }
    cout << cnt << endl;
}