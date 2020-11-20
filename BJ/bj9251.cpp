#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001];

pair< pair<int, int>, int > func_(string A, string B){
    
    int max_val = 0;
    int row=0, col=0;
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<B.size(); j++){
            if(A[i]==B[j]) dp[i+1][j+1] = dp[i][j]+1;
            else{
                dp[i+1][j+1] = max(dp[i][j+1] , dp[i+1][j]);
            }
            if(max_val < dp[i+1][j+1]){
                max_val = dp[i+1][j+1];
                row = i+1;
                col = j+1;
            }
        }
    }
    return make_pair( make_pair(row, col), max_val);
}

int main(void){
    string A, B;
    cin >> A >> B;
    
    pair< pair<int,int> , int> X;
    X = func_(A, B);
    
    cout << X.second << endl;
   
return 0;
}