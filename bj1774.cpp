#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct pos{
    int x, y;
};
struct edge{
    int a, b;
    double dist;
    edge(int a, int b, double dist){
        this->a = a;
        this->b = b;
        this->dist = dist;
    }
};

double distance(pos a , pos b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}

int root[1001];

int find_func(int x){
    if(root[x] == x) return x;
    else return root[x] = find_func(root[x]);
}
void union_func( int x, int y){
    x = find_func(x);
    y = find_func(y);
    if(x==y) return;
    else{
        root[y] = x;
        //cout << "here: "<<root[y] << " "<< x << endl;
    }
}
bool compare(edge a, edge b){
    if(a.dist < b.dist) return true;
    else return false;
}

int main(void){
    int N, M;
    cin >> N >> M;
    pos* arr = new pos[N];
    for(int i=0; i<N; i++){
        cin >> arr[i].x >> arr[i].y;
        root[i] = i;
    }
    // M개의 줄에는 이미 연결된 통로
    double sum = 0;
    for(int i=0; i<M; i++){
        int first, second;
        cin >> first >> second;
        first -= 1; //index 맞춰주기위해
        second -= 1;
        //sum += distance(arr[first], arr[second]);
        union_func(first, second);
    }
    vector<edge> E;
    //서로다른집합에 속한 모든 node들의 거리 구해주기
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(find_func(i) != find_func(j)) E.push_back(edge(i, j, distance(arr[i], arr[j])));
        }
    }
    sort(E.begin(), E.end(), compare);
    for(int i=0; i<E.size(); i++){
        int p, q;
        p = E[i].a;
        q = E[i].b;
        if(find_func(p) != find_func(q)) {
            sum+=E[i].dist;
            union_func(p, q);
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout << sum << endl;
    return 0;
}