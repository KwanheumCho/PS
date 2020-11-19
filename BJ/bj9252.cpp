#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string A, B;
int dp_[1002][1002];

int main(void){
    cin >> A >> B;
    // LCS(i,j) = LCS(i-1,j-1)+1
    // LCS(i,j) = max( i-1, j  , j-1, i)
    if(A[0] == B[0]) dp_[1][1] = 1;

    for(int i=1; i<A.size(); i++){
        if(B[0] == A[i]) dp_[i+1][1] = max(dp_[i][1], 1);
        else dp_[i+1][1] = dp_[i][1];
    }
    for(int i=1; i<B.size(); i++){
        if(A[0] == B[i]) dp_[1][i+1] = max(dp_[1][i], 1);
        else dp_[1][i+1] = dp_[1][i];
    }
    int max_val = 0;
    int row =0 , col = 0;
    for(int i=1; i< A.size(); i++){
        for(int j=1; j< B.size(); j++){
            //A의 i번째, B의 j번째
            //index는 +1씩 더해줘 나중을 위해
            //dp_[i+1][j+1]
            if(A[i]==B[j]){
                dp_[i+1][j+1] = dp_[i][j] + 1;
            }
            else{
                dp_[i+1][j+1] = max( dp_[i][j+1] , dp_[i+1][j]);
            }
            if(max_val < dp_[i+1][j+1]){
                max_val = dp_[i+1][j+1];
                row = i+1;
                col = j+1;
            }
        }
    }
    string answer = "";
    while(true){
        //cout << "row: " << row << " col: " << col << endl;
        if(row==0 || col==0) break;
        if(dp_[row][col] > dp_[row-1][col-1] && dp_[row][col] > dp_[row][col-1] && dp_[row][col]>dp_[row-1][col]){
            answer = A[row-1] + answer;
            row--;
            col--;
        }
        else if(dp_[row][col] > dp_[row-1][col] && dp_[row][col]==dp_[row][col-1]){
            col--;
        }
        else{
            row--;
        }
    }
    if(max_val >0) cout << max_val << '\n' << answer << endl;
    else cout << 0 << endl;
    //cout << max_val << endl;
    return 0;
}