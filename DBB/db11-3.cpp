#include <iostream>
#include <string>
using namespace std;

int main(void){
    string input;
    cin >> input;
    // 1000100101
    // 101001
    // 연속된 1 or 0을 하나로 잡고 더 적은숫자
    int arr[2] = {0,};
    char before = input[0];
    arr[(before-'0')] = 1;
    
    for(int i=1; i<input.size(); i++){
        if(input[i] != before){
            before = input[i];
            arr[(before-'0')]++;
        }
    }
    if(arr[0] < arr[1]) cout << arr[0] << endl;
    else cout << arr[1] << endl;

    return 0;
}