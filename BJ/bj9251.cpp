#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string A, B;
    cin >> A >> B;
    int a_size = A.size();
    int b_size = B.size();
    int** arr = new int*[a_size+1];
    string** s = new string*[a_size+1];
    for(int i=0; i<a_size+1;i++){
        arr[i] = new int[b_size+1];
        s[i] = new string[b_size+1];
        for(int j=0; j<b_size+1; j++){
            arr[i][j] = 0;
            s[i][j] ="";
        }
    }
    int ans = 0;
    int tmp;
    for(int i=1; i<=a_size; i++){
        for(int j=1; j<=b_size; j++){
            
                if(A[i]==B[j]) arr[i][j] = arr[i-1][j-1] +1;
                else{
                    if(arr[i][j-1] > arr[i-1][j]) arr[i][j] = arr[i][j-1];
                    else arr[i][j] = arr[i-1][j];
                }
            
            tmp = arr[i][j];
            //cout << tmp <<" "<< i<<" " << j << endl;
            if( tmp > ans) ans = tmp;
        }
    }
    cout << ans << endl;

    return 0;
}