#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000][3];
int dp[1000][3];

int main(void){
    int house_number; // <= 1000
    cin >> house_number;
    for(int i= 0; i< house_number; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for(int i=1; i<house_number; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }
    int result = min(dp[house_number-1][0], min(dp[house_number-1][1], dp[house_number-1][2]));
    cout << result << endl;

}