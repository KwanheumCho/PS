#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define INF 1e9
int main(void){
    int n, m;
    cin >> n >> m;
    int arr[101][101];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        int a, b, x;
        cin >> a >> b >> x;
        arr[a][b] = min(arr[a][b], x);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j] == INF) arr[i][j] = 0;
            cout<< arr[i][j] << " ";
        }
        cout << endl;
    }
}