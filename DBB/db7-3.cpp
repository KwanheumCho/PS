#include <iostream>
#include <queue>
using namespace std;


int arr_[1000001];
int main(void){
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr_[i];
    }
    int start = 1;
    int end = 2000000000;
    int answer;
    while(start<=end){
        int mid = (start+end)/2; // 절단기 길이
        cout << mid << endl;
        int x = 0;
        for(int i=0; i<N; i++){
            if(arr_[i] > mid){
                x += arr_[i] - mid;
            }
        }
        if(x > M){ //필요한 떡보다 더 길어 => 절단기를 더 길게
            start = mid+1; //
            answer = mid;
        }
        else if(x < M){
            end = mid-1;
        }
        else{
            answer = mid;
            break;
        }
    }
    cout << answer << endl;
    return 0;
}