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
    vector< pair<int, pair<int, int> > >v;
    int total_result = 0;
    for(int i=0; i<m; i++){
        int a, b, cost;
        cin >> a>>b>>cost;
        v.push_back({cost , {a, b}});
        total_result += cost;
    }
    int* parent = new int[n];
    for(int i=0; i<n; i++) parent[i] = i;

    sort(v.begin(), v.end());
    int tmp_result = 0;
    for(int i=0; i<v.size(); i++){
        int x, y, cost;
        x = v[i].second.first;
        y = v[i].second.second;
        cost = v[i].first;
        if(find_parent(parent, x) != find_parent(parent, y)){
            union_(parent, x, y);
            tmp_result += cost;
        }
    }

    cout << total_result - tmp_result << endl;
}