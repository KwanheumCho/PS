#include <iostream>

using namespace std;
long long answer = 0;
long long sorted[500000];
void merge(long long* arr, int left, int mid, int right){
    int i= left, j=mid+1;
    int k= left;
    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){
            answer += k-i;
            //cout << "k: "<<k<<"i: "<<i<<endl;
            sorted[k++] = arr[i++];
        }
        else{
            sorted[k++] = arr[j++];
        }
    }
    if(i>mid){
        for(j; j<=right; j++){
            sorted[k++] = arr[j];
        }
    }
    else{
        for(i; i<=mid; i++){
            answer += k-i;
            sorted[k++] = arr[i];
        }
    }
    for(int a=left; a<=right; a++){
        arr[a] = sorted[a];
    }
}

void merge_sort(long long* arr, int left, int right){
    int mid = (left+right)/2;
    if(left<right){
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(void){
    int N;
    cin >> N;
    long long* arr = new long long[N];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    // Bubble sort
    
    merge_sort(arr, 0, N-1);
    /*
    for(int i=0; i<N; i++){
        cout << arr[i] << endl;
    }
    */
    cout << answer << endl;
}