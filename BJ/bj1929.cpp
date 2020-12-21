#include <iostream>

using namespace std;

int main(void){
    int m, n;
    cin >> m >> n;
    //모든소수를 구해서 생각
    bool* chk = new bool[n+1]{false,};
    chk[1] = true;
    //false means prime number;
    for(int i=2; i<=n; i++){
        //cout << "i: " << i << endl;
        if(!chk[i]){
            int m=2;
            while(m*i<=n){
                if(!chk[m*i]){
                    chk[m*i] = true; // i의 배수들을 소수에서 제외
                    m++;
                    //cout << m << endl;
                }
                else m++;
            }
        }
    }
    for(int j=m; j<=n; j++){
        if(!chk[j]) cout << j << '\n';
    }

    return 0;
}