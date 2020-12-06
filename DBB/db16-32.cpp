#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int arr[501][501];
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> arr[i][j];
        }
    }
    int dp[501][501];
    dp[0][0] = arr[0][0]; // 시작점
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            int left , right;
            if(j==0){
                //왼쪽위 불가능
                left = 0;
                right = dp[i-1][j];
            }
            else if(j==i){
                right = 0;
                left = dp[i-1][j-1];
            }
            else{
                left = dp[i-1][j-1];
                right = dp[i-1][j];
            }
            dp[i][j] = arr[i][j] + max(left, right);
        }
    }
    int max_val = 0;
    for(int k=0; k<n; k++){
        max_val = max(max_val, dp[n-1][k]);
    }
    cout << max_val << endl;
    return 0;
}