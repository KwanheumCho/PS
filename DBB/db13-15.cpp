#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//int map_[]
int main(void){
    int N, M, K, X;
    cin >> N  >> M >> K >> X ;
    vector<int>* map_ = new vector<int>[N+1];
    for(int i=0; i< M; i++){
        int a, b;
        cin >> a>> b;
        map_[a].push_back(b);
    }
    int* dist_ = new int[N+1];
    for(int i=1; i<=N; i++){
        dist_[i] = 100000;
    }
    bool* chk_ = new bool[N+1];
    queue<int> q;
    chk_[X] = true;
    q.push(X);
    dist_[X] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i<map_[node].size(); i++){
            int dest = map_[node][i];
            if(!chk_[dest]){
                dist_[dest] = min(dist_[node]+1 , dist_[dest]);
                chk_[dest] = true;
                q.push(dest);
            }
        }
    }
    bool flag= false;
    for(int i=1; i<=N; i++){
        if(dist_[i]==K){
            cout << i << '\n';
            flag = true;
        }
    }
    if(!flag) cout << -1 << endl;
}