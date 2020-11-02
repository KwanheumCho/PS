#include <iostream>
#include <algorithm>
using namespace std;



int main(void){
    int number, max_weight;
    cin >> number >> max_weight;
    int* weight_arr = new int[number+1];
    int* value_arr = new int[number+1];
    int answer =0;
    for(int i=1; i<=number; i++){
        cin >> weight_arr[i] >> value_arr[i];
    }
    int** dp = new int*[number+1];
    for(int i=0; i<=number; i++){
        dp[i] = new int[max_weight+1];
        for(int j=0; j<=max_weight; j++){
            dp[i][j] = 0;
        }
    }
    int result = 0;
    for(int i=1; i<=number; i++){
        for(int j=1; j<=max_weight; j++){
            if(weight_arr[i] <= j){
                dp[i][j] = max(value_arr[i]+dp[i-1][j-weight_arr[i]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            result = max(dp[i][j], result);
        }
    }



    cout << result << endl;
    return 0;
}