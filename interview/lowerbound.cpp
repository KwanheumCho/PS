#include <iostream>

using namespace std;

int main(void){
    int arr[] = {1, 1, 2, 2, 2, 3, 4, 4, 4, 4, 5, 5, 6, 6}; //14개의 정렬된 배열
    int target;
    cin >> target;

    //분할정복
    int left = 0;
    int right = 13;
    while(left < right){
        int mid = (left+right) / 2;
        if(arr[mid] < target){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    int lower_bound = left;
    left = 0;
    right = 13;
    while(left < right){
        int mid = (left+right) / 2;
        if(arr[mid] <= target){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    int upper_bound = right;
    int answer = upper_bound - lower_bound;
    cout << answer << endl;




}