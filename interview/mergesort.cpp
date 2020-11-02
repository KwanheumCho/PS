#include <iostream>
using namespace std;
#define SIZE 9

int sorted[SIZE];

void merge(int* arr, int left, int mid, int right){
    int i=left, j=mid+1; // 두개의 합쳐야되는 배열의 시작점 i, j;
    int k=left; // 합친 결과를 저장하는 배열의 시작점 k;
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            sorted[k++] = arr[i++];
        }
        else{
            sorted[k++] = arr[j++];
        }
    }
    if( i > mid){
        for(j; j<=right; j++) sorted[k++] = arr[j];
    }
    else{
        for(i; i<=mid; i++) sorted[k++] = arr[i];
    }
    for(int x=left; x<=right; x++){
        arr[x] = sorted[x];
    }
}
void merge_sort(int* arr, int left, int right){
    if(left<right){ // entity가 1개 이상이면 계속 쪼개야합니다.
        int mid = (left+right)/2;
        merge_sort(arr, left, mid); // entity가 1개면 안쪼개짐
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(void){
    int arr[SIZE] = {3, 4, 1, 5, 2, 10, 13, 8, 7};
    merge_sort(arr, 0, SIZE-1);
    for(int i=0; i<SIZE; i++){
        cout<<arr[i];
    }
    return 0;
}