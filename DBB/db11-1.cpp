#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    //그룹 수의 최대값
    int N;
    cin >> N;
    //공포도가 낮은 놈부터 , 최소의 인원에 맞게 구성
    int* arr = new int[N+1];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    int i = 0;
    int group = 1;
    int gongpo = arr[i];
    int answer = 0;
    //3 3 4
    // 현재 확인하고 있는 공포감 : gongpo
    // 현재 확인하고 있는 공포감이 포함되어 있는 그룹의 인원 수 : group
    // 같을 때 그룹생성. 안같으면 계속 추가
    while(i < N){
        if(gongpo == group){
            answer ++;
            group = 1;
            i++;
            gongpo = arr[i];
        }
        else{
            group++;
            i++;
            gongpo = arr[i];
        }
    }
    cout << answer << endl;


    return 0;
}