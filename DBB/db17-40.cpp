#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define INF 1e9
int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> v[20001];
    int dist[20001];
    for(int i=1; i<=n; i++) dist[i] = INF;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a>> b;
        v[a].push_back(b);
        v[b].push_back(a); // 거리는 어차피 모두 1
    }
    //시작점 : 1
    dist[1] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push( {0, 1}); // dist, node number
    while(!pq.empty()){
        int distance = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(dist[node] < distance) continue;
        for(int j=0; j<v[node].size(); j++){
            int cost = 1;
            int next = v[node][j];
            if( dist[next] > distance+cost) {
                dist[next] = distance+cost;
                pq.push({ -(distance+cost), next});
            }
        }
    }
    int idx = 0;
    int cnt = 0;
    int max_val = 0;
    for(int i=1; i<=n; i++){
        if(max_val < dist[i]){
            idx = i;
            max_val = dist[i];
            cnt=1;
        }
        else if(max_val == dist[i]) cnt++;
    } 
    cout << idx <<" "<< max_val << " "<<cnt << endl;


    return 0;
}