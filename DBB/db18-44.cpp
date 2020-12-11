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
struct pos{
    int x, y, z;
    int number;
};
int calc_dist(pos A, pos B){
    return min(abs(A.x-B.x), min(abs(A.y-B.y), abs(A.z-B.z)));
}
bool comp_x(pos A, pos B){
    return A.x < B.x;
}
bool comp_y(pos A, pos B){
    return A.y < B.y;
}
bool comp_z(pos A, pos B){
    return A.z < B.z;
}


int main(void){
    int n;
    cin >> n;
    int* parent = new int[n+1];
    for(int i=1; i<=n; i++) parent[i] = i;
    pos* arr = new pos[n+1];
    for(int i=1; i<=n; i++){
        int a, b, c;
        cin >> a>>b>>c;
        arr[i] = {a, b, c, i};
    }
    /* 거리를 모두 구하게 되면 메모리 초과....!!
    vector< pair<int , pair<int, int> > > v;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(i!=j){
                int dist = calc_dist( arr[i], arr[j]);
                v.push_back( {dist , {i, j}} );
            }
        }
    }
    */
    vector< pair<int , pair<int, int> > > v;
    sort(arr+1 , arr+n+1, comp_x);
    for(int i=1; i<=n-1; i++){
        int dist = abs(arr[i].x - arr[i+1].x);
        v.push_back( {dist , {arr[i].number, arr[i+1].number }} );
    }
    sort(arr+1 , arr+n+1, comp_y);
    for(int i=1; i<=n-1; i++){
        int dist = abs(arr[i].y - arr[i+1].y);
        v.push_back( {dist , {arr[i].number, arr[i+1].number }} );
    }
    sort(arr+1 , arr+n+1, comp_z);
    for(int i=1; i<=n-1; i++){
        int dist = abs(arr[i].z - arr[i+1].z);
        v.push_back( {dist , {arr[i].number, arr[i+1].number }} );
    }

    
    sort(v.begin(), v.end());
    int result = 0;
    for(int i=0; i<v.size(); i++){
        int x = v[i].second.first;
        int y = v[i].second.second;
        int cost = v[i].first;
        if(find_parent(parent, x) != find_parent(parent, y)){
            union_(parent, x, y);
            result += cost;
        }
    }
    cout << result << endl;
    


    return 0;
    }