#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int* list = new int[N+1];
    list[1] = 1;
    list[2] = 2;
    list[3] = 3;
    for(int i=4; i<N+1; i++){
        list[i] = (list[i-1] + list[i-2])%15746;
    }
    cout << list[N] << endl;
}