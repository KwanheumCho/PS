#include <iostream>
using namespace std;

int main(void){
    int N;
    long long K;
    cin >> N >> K;
    int* value_list = new int[N]; // value list is arranged by ascending order.
    for(int i=0; i<N; i++){
        cin >> value_list[i];
    }
    int result = 0;
        for(int k=N-1; k>=0; k--){
            if(value_list[k] <= K){
                result += K / value_list[k];
                K = K%value_list[k];
            }
        }
    cout << result << endl;     

}