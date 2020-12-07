#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int arr[2001];
    for(int i=1; i<=n; i++)
    {   
        cin >> arr[i];
    }
    int dp[2001];
    //dp[i] = i th 값을 포함할때의 최대개수
    for(int i=1; i<=n; i++) dp[i] = 1;
    for(int i=2; i<=n; i++){
        int lower = arr[i];
        for(int j=i-1; j>=1; j--){
            if(arr[j] > lower){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int max_val = 0;
    for(int i=1; i<=n; i++){
        //cout << dp[i] << endl;
        max_val = max(max_val, dp[i]);
    }
    cout << n - max_val << endl;

}