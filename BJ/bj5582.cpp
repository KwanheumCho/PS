#include <iostream>
#include <string>
using namespace std;

int main(){
    string A, B;
    cin >> A >> B;
    int a_size = A.size();
    int b_size = B.size();
    int** arr = new int*[a_size];
    for(int i=0; i<a_size;i++){
        arr[i] = new int[b_size];
        for(int j=0; j<b_size; j++){
            arr[i][j] = 0;
        }
    }
    int ans = 0;
    int p = 0;
    for(int i=0; i<a_size; i++){
        for(int j=0; j<b_size; j++){
            if(A[i] == B[j]){
                if(i ==0 || j==0){
                    p = ++arr[i][j];
                    if(p > ans) ans =p;
                }
                else if(i!=0 && j!=0){
                    arr[i][j] = arr[i-1][j-1]+1;
                    //cout<<i<<" " << j<<" "<<p<<endl;
                    p = arr[i][j];
                }
            }
            if(p > ans) ans = p;
        }
    }
    cout << ans << endl;
    return 0;
}