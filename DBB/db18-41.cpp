#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define INF 1e9

int find_parent(int* parent, int x){
    if(parent[x] != x){
        parent[x] = find_parent(parent, parent[x]);
    }
    return parent[x];
}

void union_(int* parent, int a, int b){
    a = find_parent(parent, a);
    b = find_parent(parent, b);
    if(a < b){
        parent[b] = a;
    }
    else if(a>b){
        parent[a] = b;
    }
}

int main(void){
    int n, m;
    cin >> n >> m;
    int* parent = new int[n+1];
    for(int i=1; i<=n; i++) parent[i] = i;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin >> x;
            if(x == 1){
                if(find_parent(parent, i) != find_parent(parent, j)){
                    union_(parent, i, j);
                }
            }
        }
    }
    int* arr = new int[m];
    for(int i=0; i<m; i++){
        cin >> arr[i];
    }
    for(int i=0; i<m-1; i++){
        int a, b;
        a = arr[i];
        b = arr[i+1];
        if( find_parent(parent, a) != find_parent(parent, b)){
            cout << "NO" << endl;
            break;
        }
        if(i==m-2){
            cout << "YES" << endl;
        }
    }

}