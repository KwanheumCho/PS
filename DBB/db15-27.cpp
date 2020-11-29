#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int lower_bound(int* arr, int start, int end, int target){
    int idx = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid] >= target){
            idx = mid;
            end = mid-1;
        }
        else if(arr[mid] < target){
            start = mid+1;
        }
    }
    return idx;
}
int upper_bound(int* arr, int start, int end, int target){
    int idx = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid] > target){
            
            end = mid-1;
        }
        else if(arr[mid] <= target){
            start = mid+1;
            idx = mid;
        }
    }
    return idx;
}

int main(void){

    int N, X;
    cin >> N >> X;
    
    int arr[1001];
    for(int i=0; i< N; i++){
        cin >> arr[i];
    }
    
    int start = 0;
    int end = N-1;
    int idx = 0;
    int lower = lower_bound(arr, start, end, X);
    int upper = upper_bound(arr, start, end, X);
    //cout << "lower: "<<lower << "upper: "<<upper << endl;
    if(lower>-1 && arr[lower]==X && arr[upper]==X){
        cout << upper-lower+1<<endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}