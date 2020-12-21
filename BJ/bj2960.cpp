#include <iostream>
using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;
    bool* chk = new bool[n+1]{false,};
    int* arr = new int[n+1];
    //false means not yet delete;
    int idx = 2;
    int cnt = 1;
    while( idx <=n ){
        if(!chk[idx]){
            chk[idx] = true;
            arr[cnt++] = idx;
            int m = 2;
            while(m*idx <= n){
                if(!chk[m*idx]){
                    chk[m*idx] = true;
                    arr[cnt++] = m*idx;
                }
                m++;
            }
        }
        idx++;
    }
    //for(int i=1; i<=k; i++) cout << arr[i] << endl;
    cout << arr[k] << endl;
    return 0;
}