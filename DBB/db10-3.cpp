#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define INF 1e9

int find_parent(int* p_arr, int x){
    if(p_arr[x] != x){
        p_arr[x] = find_parent(p_arr, p_arr[x]);//경로단축
    }
    return p_arr[x];
}

void union_(int* p_arr, int a, int b){
    a = find_parent(p_arr, a);
    b = find_parent(p_arr , b);
    if(a<b){
        p_arr[b] = a;
    }
    else if(a>b){
        p_arr[a] = b;
    }
}

int main(void){
    int n, m;
    cin >> n >> m;
    vector< pair<int, pair<int, int> > > v;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a>> b>> c;
        v.push_back({c, {a, b}});
    }
    int* p_arr = new int[n+1];
    for(int i=1;i<=n;i++) p_arr[i] = i; //자기자신이 부모
    sort(v.begin(), v.end());
    int result = 0;
    int max_val = 0;
    for(int i=0; i<v.size(); i++){
        int a=v[i].second.first;
        int b=v[i].second.second;
        int cost = v[i].first;
        if(find_parent(p_arr, a) != find_parent(p_arr, b)){
            union_(p_arr, a, b);
            result += cost;
            max_val = max(max_val, cost);
        }
    }
    //도시를 2분할
    cout << result - max_val << endl;



}