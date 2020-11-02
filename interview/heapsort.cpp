#include <iostream>
using namespace std;
#define SIZE 100
/*
struct element{
    int key=0;
};
struct heap{
    element heap_array[SIZE];
    int length = 0;
};
//insert heap, delete heap
void insert_max_heap(heap *h, element item){
    int i;
    i = ++h->length;
    // i means heap size and we already insert item so i+1
    while((i!=1) && (item.key > h->heap_array[i/2].key)){
        h->heap_array[i] = h->heap_array[i/2];
        i/=2;
    }
    h->heap_array[i] = item; 
    //cout << "i: "<< i << " key: " << item.key<<endl;
}
element delete_max_heap(heap *h){
    element result = h->heap_array[1];
    element tmp = h->heap_array[(h->length)--];
    int k = 1;
    int i = 2;
    while( (i <= h->length)){
        if( (i < h->length) && (h->heap_array[i].key < h->heap_array[i+1].key)){
            i = i+1;
        }
        if( tmp.key >= h->heap_array[i].key){
            break;
        }
        h->heap_array[k] = h->heap_array[i];
        k = i;
        i *= 2;
    }
    h->heap_array[k] = tmp;

    return result;
}
void heap_sort(element a[], int n){

    int i;
    heap h;
    for(int i=0; i<n; i++){
        insert_max_heap(&h, a[i]);
    }
    for(int i=n-1; i>=0; i--){
        a[i] = delete_max_heap(&h);
        //cout << a[i].key <<endl;
    }
}

int main(void){
    element a[10] ={9, 7, 6, 5, 4, 3, 2, 2, 1, 3};
    heap_sort(a, 10);
    
    for(int i=0; i<10; i++){
        cout << a[i].key << endl;
    }
    
    return 0;
}
*/
/*
int number = 9;
int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};
int main(void){
    //heap을 구성
    for(int i=1; i<number; i++){
        int c = i;
        while(c>0){
        int parent = (c-1)/2;
        if(heap[parent]<heap[c]){
            int tmp = heap[c];
            heap[c] = heap[parent];
            heap[parent] = tmp;
        }
        else break;
        c = parent;
        }
    }
    for(int i=0; i< number; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
    for(int i=number-1; i>=0; i--){
        int tmp = heap[0];
        heap[0] = heap[i];
        heap[i] = tmp;
        int parent = 0;
        int child = 1;
        while(child < i){
            if(child <i-1 && heap[child] < heap[child+1]){
                child++;
            }
            if(child < i && heap[parent] < heap[child]){
                tmp = heap[parent];
                heap[parent] = heap[child];
                heap[child] = tmp;
            }
            else break;
            parent = child;
            child = parent*2 + 1;
        }
    }
    for(int i=0; i< number; i++){
        cout << heap[i] << " ";
    }
}
*/
int number;
int heap[1000001];

void heapify(int i){
    int c = 2*i + 1;
    if( c < number-1 && heap[c] < heap[c+1] ){
        c++;
    }
    if( c< number && heap[i] < heap[c]){
        int tmp = heap[i];
        heap[i] = heap[c];
        heap[c] = tmp;
    }
    if( c <= number/2 -1 ) heapify(c);
}
int main(void){
    cin >> number;
    for(int i=0; i<number; i++){
        cin >> heap[i];
    }
    for(int i=number/2-1; i>=0; i--){
        heapify(i);
    }
    for(int i=0; i<number; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
    for(int i=number-1; i>=0; i--){
        int tmp = heap[0];
        heap[0] = heap[i];
        heap[i] = tmp;
        int parent = 0;
        int child = 1;
        while(child < i){
            if(child <i-1 && heap[child] < heap[child+1]){
                child++;
            }
            if(child < i && heap[parent] < heap[child]){
                tmp = heap[parent];
                heap[parent] = heap[child];
                heap[child] = tmp;
            }
            else break;
            parent = child;
            child = parent*2 + 1;
        }
    }
    for(int i=0; i<number; i++){
        cout << heap[i] << " ";
    }
}