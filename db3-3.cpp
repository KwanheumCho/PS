#include <iostream>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    int max_val = 0;
    for(int i=0; i< N; i++){
        int min_val = 10001;
        for(int j=0; j<M; j++){
            int x;
            cin >> x;
            if(x < min_val) min_val = x; 
        }
        if(min_val > max_val) max_val = min_val;
    }
    cout << max_val;
}