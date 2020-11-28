#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_VAL 1000000000
int N;

int calc_(int op, int a, int b){
    if(op == 0){
        return a+b;
    }
    else if(op == 1){
        return a-b;
    }
    else if(op==2){
        return a*b;
    }
    else if(op == 3){
        if(a < 0) return -((-a)/b);
        else return (a/b);
    }
}
int max_val = -MAX_VAL;
int min_val = MAX_VAL;
void func_(int* arr, int* op, int cnt, int result){
    if(cnt == N-1){
        max_val = max(result, max_val);
        min_val = min(result, min_val);
    }
    for(int i=0; i<4; i++){
        if(op[i] != 0){
            int tmp = calc_(i, result, arr[cnt+1]);
            //cout << tmp << endl;
            op[i]--;
            func_(arr, op, cnt+1, tmp );
            op[i]++;
        }
    }
}

int main(void){
    
    cin >> N;
    int arr[12];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    int op[4];
    for(int i=0; i<4; i++){
        cin >> op[i]; // + - X /  
    }

    func_(arr, op, 0, arr[0]);
    cout << max_val << endl;
    cout << min_val << endl;
    return 0;
}