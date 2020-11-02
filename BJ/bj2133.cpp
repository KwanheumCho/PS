#include <iostream>
using namespace std;

int arr[31] = {0, };
int main(void){

    int n;
    cin >> n;
    arr[1] = 0;
    arr[2] = 3;
    arr[3] = 0;
    arr[4] = 11;
    //cout<< arr[6] << arr[8] << endl;
    if(n>4 && n%2 ==0){ // 홀수면 못채워
        int i = 6;
        while(i<=n){
            //arr[i] = arr[i-2] * 3 + arr[i-4] * 2+ 2;
            arr[i] += arr[i-2] * 3 + 2;
            for(int j=4; j<i; j+=2){
                arr[i] += arr[i-j] * 2;
            }
            i+=2;
        }
    }
    cout << arr[n] << endl;
}