#include <iostream>
using namespace std;
#define SIZE 6
//# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

void SWAP( int& a, int&b){
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

int partition(int arr[], int left, int right){
    int low = left;
    int high = right+1;
    int pivot = arr[left]; // 제일왼쪽이 pivot;
    int temp;
    do{
        do{
            low++;
        }while(low<=right && arr[low]<pivot);
        do{
            high--;
        }while(high>=left && arr[high]>pivot);
        if(low<high) SWAP(arr[low], arr[high]);
    }while(low<high);
    SWAP(arr[left], arr[high]);

    return high;
}

void quick_sort(int arr[], int left, int right){
    if(left<right){
        int q = partition(arr, left, right);

        quick_sort(arr, left, q-1);
        quick_sort(arr, q+1, right);
    }
}

int main(void){
    int list[SIZE] = {5, 3, 8, 4, 9, 1};
    quick_sort(list , 0, SIZE-1);
    for(int i=0; i<SIZE; i++){
        cout<<list[i]<<" ";
    }
    return 0;
}