#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int* arr = new int[n+1]; // index
    arr[1] = 1;
    arr[2] = 2;
    
    if(n>2){
        for(int i=3; i<=n;i++){
            arr[i] = arr[i-1]%10007 + arr[i-2]%10007;
            arr[i] = arr[i]%10007;
        }
    }
    
    cout << arr[n] << endl;
    


}