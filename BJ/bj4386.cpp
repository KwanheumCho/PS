#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct pos{
    float x, y;
};

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

float calc_dist(pos A, pos B){
    return sqrt( pow(A.x-B.x , 2) + pow(A.y-B.y, 2));
}


int main(void){
    int n;
    cin >> n;
    int* parent = new int[n+1];
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    pos* arr = new pos[n+1];
    for(int i=1; i<=n; i++){
        float x, y;
        cin >> x >> y;
        arr[i].x = x;
        arr[i].y = y;
    }
    vector< pair< float, pair<int, int> > > v;
    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            float dist = calc_dist(arr[i], arr[j]);
            v.push_back( {dist, {i,j}});
        }
    }
    sort(v.begin(), v.end());
    float result = 0;
    for(int i=0; i<v.size(); i++){
        float cost = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;
        if(find_parent(parent, a) != find_parent(parent, b)){
            union_(parent, a, b);
            result += cost;
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout << result << endl;
}