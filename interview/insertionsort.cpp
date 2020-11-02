#include <iostream>
using namespace std;

int main(void){
    int i, j, key, tmp;
    int n = 5;
    int list[5] = {8, 5, 6, 2, 4};
    for(int i=1; i<n; i++){
        key = list[i];
        for(j=i-1; j>=0 && list[j]>key;j--){
            list[j+1] = list[j];
            tmp = j;
        }
        list[tmp] = key;
    }
    for(int i=0; i<n; i++){
        cout << list[i] << " ";
    }

}