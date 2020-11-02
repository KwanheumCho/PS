#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
vector<int> arr;

int main(void){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
}
*/
int arr[1000];
void quickSort(int* arr, int start, int end){
    if(start>=end) return;
    int pivot = arr[start];
    int i= start+1, j= end;
    while(i<=j){
        while(pivot > arr[i] && i<=end){
            i++;
        }
        while(pivot < arr[j] && j>start){
            j--;
        }
        int tmp;
        if(i>j){
            tmp = arr[j];
            arr[j] = arr[start];
            arr[start] = tmp;
        }
        else{
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
    quickSort(arr, start, j-1);
    quickSort(arr, j+1, end);
}

int main(void){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, N-1);
    for(int i=0; i<N; i++){
        cout << arr[i] << endl;
    }

    return 0;
}