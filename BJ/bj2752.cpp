#include <iostream>
using namespace std;

int arr[3];

int main(void){
    for(int i=0; i<3; i++){
        cin >> arr[i];
    }
    int min;
    for(int i=0; i<3; i++){
        min = 1000001;
        for(int j=i; j<3; j++){
            if(min > arr[j]){
                min = arr[j];
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
    for(int i=0; i<3; i++) cout << arr[i] <<" ";
    return 0;
}