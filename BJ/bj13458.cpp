#include <iostream>
using namespace std;

int main(){

    int N, B, C;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    cin >> B >> C;
    //B : 총감독관 C: 부감독관
    // 총감독관 오직 1명, 부감독과 ㄴ여러명
    // 감독관 수의 최소.
    long long result = 0;
    for(int i=0; i<N; i++){
        arr[i] -= B;
        result++;
        long long tmp=0;
        if(arr[i]>0){
            if(arr[i]%C ==0) tmp = arr[i]/C;
            else tmp = (arr[i] / C) + 1;
        }
        result += tmp;
    }
    cout << result;
}