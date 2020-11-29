#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N ;
    
    int arr[1001];
    for(int i=0; i< N; i++){
        cin >> arr[i];
    }
    int start = 0;
    int end = N-1;
    bool flag= false;
    while(start<=end){ // target이 곧 배열의 인덱스라고 생각.
        int mid = (start+end)/2;
        if(arr[mid] > mid){
            end = mid-1;
        }
        else if(arr[mid] < mid){
            start = mid+1;
        }
        else{
            cout << mid << endl;
            flag = true;
            break;
        }
    }
    if(!flag) cout << -1 << endl;
}