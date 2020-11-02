#include <iostream>
#include <algorithm>
using namespace std;

int stair[300];
int dp[300];

int main(void){
    int number;
    cin >> number;
    for(int i=0; i< number; i++){
        cin >> stair[i];
    }
    // 마지막을 반드시 밟아야함.
    dp[0] = stair[0];
    dp[1] = dp[0] + stair[1];
    dp[2] = max(stair[1]+stair[2], stair[0]+stair[2]);
    //cout << "1:"<< dp[1] << "sa" << stair[2] << endl;
    // dp(x) 는 x번째 칸을 밟았을 때 최대가 되는 값.
    for(int i=3; i<number; i++){
        dp[i] = max( dp[i-3]+stair[i-1]+stair[i] , dp[i-2] + stair[i]);
    }
    cout << dp[number-1] << endl;

}