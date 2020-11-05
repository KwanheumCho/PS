#include <iostream>
#include <vector>
#include <string>
using namespace std;

int arr_road[201][201];
int N, M;
int parent[201];

int find_parent(int x){
    if(x == parent[x]) return x;
    else{
        return parent[x] = find_parent(parent[x]);
    }
}

void merge(int x, int y){
    x = find_parent(x);
    y = find_parent(y);
    if(x==y) return;
    else {
        parent[y]  = x;
        return;
    }
}
// 갈 수 있다의 의미를 그래프적으로 잘 파악하는 것이 중요한 문제

int main(void){
    cin >> N;
    cin >> M;
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<= N; j++){
            int x;
            cin >> x;
            if(x==1){
                merge(i, j);
            }
        }
    }
    int* arr = new int[M];
    for(int i=0; i<M; i++){
        cin >> arr[i];
    }
    string result = "";
    for(int i=0; i<M-1; i++){
        if(find_parent(arr[i]) != find_parent(arr[i+1])){
            result = "NO";
            break;
        }
        if(i==M-2){
            result = "YES";
        }
    }
    cout << result << endl;
}