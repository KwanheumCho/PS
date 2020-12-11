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

void union_(int* parent, int a){
    a = find_parent(parent, a);
    int b = find_parent(parent, a-1);
    if(a < b){
        parent[b] = a;
    }
    else if(a>b){
        parent[a] = b;
    }
}

int main(void){
    int g , p;
    cin >> g >>  p;
    int* parent = new int[g+1];
    for(int i=0; i<=g; i++){
        parent[i] = i;
    }
    int cnt = 0;
    for(int i=0; i<p; i++){
        int x;
        cin >> x;
        if(find_parent(parent, x) != 0 ){
            //cout <<"chk: "<< parent[x] <<endl;
            union_(parent, x);
            cnt++;
            cout <<"chk: "<< x <<" "<< find_parent(parent, x) <<" "<< cnt << endl;
        }
        else break;
    }
    cout << cnt << endl;

    return 0;
}