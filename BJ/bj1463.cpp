#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int* dp = new int[N+1];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4; i<=N; i++){
        if(i%3 == 0){
            dp[i] = min(dp[i/3] + 1, dp[i-1]+1);
        }
        else if(i%2 == 0){
            dp[i] = min(dp[i/2] + 1, dp[i-1]+1);
        }
        else dp[i] = dp[i-1] + 1;
    }
    cout << dp[N] << endl;

    return 0;
}