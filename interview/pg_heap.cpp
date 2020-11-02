#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct heap_sort{
    int size;
    int hT[1000000];
};
void insert_heap(heap_sort& X, int input){
    //X.hT[X.size++] = input;
    int current = X.size++; // input이 저장되어야할 point
    int child = current;
    int parent = (child-1)/2;
    X.hT[child] = input;
    while(parent >= 0 ){
        if(X.hT[parent] > input){
            int tmp = X.hT[child];
            X.hT[child] = X.hT[parent];
            X.hT[parent] = tmp;
            child = parent;
            parent = (child-1)/2;
        }
        else break;
    }   
}
int delete_heap(heap_sort& X){
    int result = X.hT[0];
    X.hT[0] = X.hT[--X.size];
    int parent = 0;
    int child = 1;
    while(child < X.size){
        if(X.hT[child] > X.hT[child+1]) child++;
        if(X.hT[child] < X.hT[parent]){
            int tmp = X.hT[child];
            X.hT[child] = X.hT[parent];
            X.hT[parent] = tmp;
            parent = child;
            child = parent * 2;
        }
        else break;
    }
   return  result;
}

long long solution(vector<int> scoville, int K) {
    long long answer = 0;
    //scoville에서 K보다 작은 값들로 구성된
    //min heap 만들어서 두개 뽑아서 더한값
    heap_sort X;
    X.size = 0;
    for(int i=0; i<scoville.size(); i++){
        insert_heap(X,scoville[i]);
    }
    while(X.size>1){
        int a = delete_heap(X);
        int b = delete_heap(X);
        if(a >=K && b >=K) return answer;
        int c = a+2*b;
        insert_heap(X, c);
        answer++;
        //cout << "while: "<<X.size << endl;
    }
    if(X.size == 1 && X.hT[0] < K) return -1;
    else return answer;
    
    //return 0;
}   