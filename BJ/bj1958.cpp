#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[101][101][101];

int func_(string A, string B, string C){
    
    int max_val = 0;
    int row=0, col=0;
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<B.size(); j++){
            for(int k=0; k<C.size(); k++){
                if(A[i]==B[j] && B[j]==C[k]){
                    dp[i+1][j+1][k+1] = dp[i][j][k] +1;
                }
                else{
                    dp[i+1][j+1][k+1] = max( max(dp[i+1][j+1][k], dp[i+1][j][k+1]), dp[i][j+1][k+1]);
                }
                if(max_val < dp[i+1][j+1][k+1]) {
                    max_val = dp[i+1][j+1][k+1];
                }
            }
        }
    }
    return max_val;
}


int main(void){
    
    string A , B , C;
    cin >> A >> B >> C;
    //first step. LCS about A & B
    int X;
    X = func_(A, B, C);
    cout << X << endl;
    return 0;
}