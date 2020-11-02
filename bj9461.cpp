#include <iostream>

using namespace std;

long long p[100];

int main(void){

    int T;
    cin >> T;
    int* n = new int[T];
    for(int i=0; i<T; i++){
        cin >> n[i];
    }
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;
    // p[i] = p[i-1] + p[i-5];
    for(int i=0; i<T; i++){
        if(n[i] >= 6){
            for(int j=6; j<=n[i]; j++){
                p[j] = p[j-1] + p[j-5];
                if(j==n[i]) cout << p[j] << endl;
            }
        }
        else{
            cout << p[n[i]] << endl;
        }
    }
}