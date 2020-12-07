#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void){
    string A, B;
    cin >> A >> B;
    int dp[101][101] =  {0,};
    for(int i=0; i<A.size(); i++){
        dp[i][0] = i;
    }
    for(int i=0; i<B.size(); i++){
        dp[0][i] = i;
    }
    for(int i=1; i<=A.size(); i++){
        for(int j=1; j<=B.size(); j++){
            if(A[i]==B[j]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i-1][j] , min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
        }
    }
    cout << dp[A.size()][B.size()] << endl;

}