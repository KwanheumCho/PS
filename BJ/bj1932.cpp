#include <iostream>
#include <algorithm>
using namespace std;

int input[500][500];
int dp[500][500];

int main(void){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            cin >> input[i][j];
        }
    }
    
    dp[0][0] = input[0][0];
    int maxvalue = 0;
    for(int i=1; i<N; i++){
        for(int j=0; j<=i; j++){
            if(j==0) dp[i][j] =  dp[i-1][j] + input[i][j];
            else if(j==i) dp[i][j] =  dp[i-1][j-1] + input[i][j];
            //else if(j==i) dp[i][j] =  dp[i-1][j] + input[i][j];
            else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + input[i][j];
            
            if(i==N-1 && dp[i][j] > maxvalue) maxvalue = dp[i][j];
        }
    }
    cout << maxvalue << endl;



}