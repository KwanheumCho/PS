#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    int * arr = new int[N+1];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    // 1 2 2 3 3
    int now_val = arr[0];
    int cnt = 1;
    int answer = 0;
    for(int i=1; i<N; i++){
        if(arr[i] == now_val){
            cnt++;
        }
        else{
            answer += cnt*(N-i);
            now_val = arr[i];
            cnt = 1;
        }
    }
    cout << answer << endl;
    return 0;
}