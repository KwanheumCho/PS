#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int dp[100000];

int main(void){
    int N;
    cin >> N;
    for(int i=0; i< N; i++){
        cin >> arr[i];
    }
    dp[0] = arr[0];
    int max_value = arr[0];
    for(int i=1; i<N; i++){
        dp[i] = max( arr[i], dp[i-1] + arr[i]);
        if(dp[i] > max_value) max_value = dp[i];
    }
    cout << max_value << endl;
}