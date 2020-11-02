#include <iostream>
using namespace std;

long long arr[1000001] = {0, };
long long arr2[1000001] = {0, };
int main(void){

    int n;
    cin >> n;
    arr[0] = 1; // default
    arr[1] = 2;
    arr[2] = 2 + 2 + 2+ 1;

    arr2[3] = 1;
    //arr[3] = arr[1] * arr[2] + 3 * arr[1] + 2;
    if(n>=3){
        for(int i=3; i<=n; i++){
            arr2[i] = arr[i-3] + arr2[i-1];
            arr[i] = (arr[i-1] * 2 + arr[i-2] * 3 + arr2[i]*2)%1000000007;
            //이중 동적프로그래밍을 사용하지 않으면 바깥쪽 for문에 다시 for문이 겹치므로 시간복잡도가 n2가 된다...
            // arr의 하나하나의 값이 modular이후에 엄청나게 큰수가 된다면, 계산과정에서 overflow가 될 수 있다. 그래서 longlong을 사용해줘야한다.
            /*
            for(int j=i-3; j>=0; j--){
                arr[i] += arr[j] * 2;
            }
            */
            //arr[i] = arr[i]%1000000007;
        }
    }
    cout<< arr[n] << endl;
}