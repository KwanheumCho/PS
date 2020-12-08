#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define INF 1e9

int find_(int* parent, int x){
    if(parent[x]!=x){
        parent[x] = find_(parent, parent[x]);
    }
    return parent[x];
}

void union_(int*parent, int a, int b){
    a = find_(parent, a);
    b = find_(parent, b);
    if(a==b) return;
    else if(a>b){
        parent[a] = b;
    }
    else parent[b] = a;

    return;
}

int main(void){
    int n, m;
    cin >> n >> m;
    int* parent = new int[n+1];
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        int inst , a , b;
        cin >> inst >> a >> b;
        //inst :0 => union // 1=> find
        if(inst==0) union_(parent, a, b);
        else{
            if(find_(parent, a) == find_(parent, b)){
                cout << "YES" << endl;
            }
            else{
                cout << " NO" << endl;
            }
        }
    }


    return 0;
}