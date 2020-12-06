#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int n, m;
        cin >> n >> m;
        int arr[21][21];
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> arr[j][k];
            }
        }
        //
        //관계식
        int dp[21][21];
        for(int j=0; j<n; j++) dp[j][0] = arr[j][0];
        for(int k=1;k<m; k++){
            for(int j=0; j<n; j++){
                if(j==0){
                    dp[j][k] = arr[j][k] + max(dp[j][k-1] , dp[j+1][k-1]);
                }
                else if(j==n-1){
                    dp[j][k] = arr[j][k] + max(dp[j][k-1] , dp[j-1][k-1]);
                }
                else{
                    dp[j][k] = arr[j][k] + max(dp[j][k-1] , max(dp[j+1][k-1], dp[j-1][k-1]));
                }
            }
        }
        
        int max_val = 0;
        for(int j=0; j<n; j++){
            max_val = max(max_val, dp[j][m-1]);
        }
        cout << max_val << endl;
    }



    return 0;
}