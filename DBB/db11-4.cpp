#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    // 현재 만들 수 있는 상태가 1~target-1 이라고 할 때, 다음 동전 X에 의해서 target을 만들 수있을까?
    // 만들 수 있다는 의미는 X <= target 이라는 의미일 것이다. => target-1+X 까지 만들 수 있을 것이다. 그러면 다음 타겟은 target + X .
    // X > target이라면 불가능.
    int N;
    cin >> N;
    int* arr= new int[N+1];
     for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    int target = 1;
    for(int i=0; i<N; i++){
        if( arr[i] <= target){
            target += arr[i];
        }
        else{
            break;
        }
    }
    cout << target << endl;




    return 0;
}

/* 내풀이
int N;
bool chk[10000001] = {false,};
int* arr= new int[N+1];
void func_(int cnt, int load){
    chk[load]= true;
    for(int i=cnt; i< N; i++){
        func_(i+1, load+arr[i]);
    }
    return;
}

int main(void){
    
    cin >> N;
    
    int* arr2 = new int[N+1];
    for(int i=0; i<N; i++){
        cin >> arr[i];
        chk[ arr[i] ] = true;
    }
    sort(arr, arr+N);
    func_(0, 0);
    int i=1;
    while(true){
        if(chk[i]==false){
             cout << i << endl;
            break;
        }
        i++;
    }

}
*/