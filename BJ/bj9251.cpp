#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp_[1001][1001];

int main(void){
    string A, B;
    cin >> A >> B;
    
    if(A[0]==B[0]) dp_[1][1] = 1;

    for(int i=1; i<B.size(); i++){
        if(A[0] == B[i]){
            dp_[1][i+1] = max(dp_[1][i], 1);
        }
        else dp_[1][i+1] = dp_[1][i];
    }
    for(int i=1; i<A.size(); i++){
        if(B[0] == A[i]){
            dp_[i+1][1] = max(dp_[i][1], 1);
        }
        else dp_[i+1][1] = dp_[i][1];
    }
    int ans = 0;
    int row, col;
    for(int j=1; j<A.size(); j++){
        for(int k=1; k<B.size(); k++){
            if(A[j] == B[k]){
                dp_[j+1][k+1] = dp_[j][k] +1;
            }
            else{
                dp_[j+1][k+1] = max(dp_[j][k+1], dp_[j+1][k]);
            }
            if(ans < dp_[j+1][k+1]) {
                ans = dp_[j+1][k+1];
                row = j+1;
                col = k+1;
                }
        }
    }
    
    string output = "";
    while(true){
        cout << "row: "<<row <<" col: "<<col << endl; 
        if(row==0 || col==0) break;
        if(dp_[row][col] > dp_[row-1][col-1] && dp_[row][col]>dp_[row-1][col] && dp_[row][col]> dp_[row][col-1]){
            output = A[row-1] + output;
            row--;
            col--;
        }
        else if(dp_[row][col] > dp_[row-1][col] && dp_[row][col] == dp_[row][col-1]){
            col--;
        }
        else if(dp_[row][col] == dp_[row-1][col]){
            row--;
        }
    }
    cout << output << endl;
    
    cout << ans << endl;
   
return 0;
}