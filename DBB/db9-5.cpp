#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int main(void){
    int n, m, C;
    cin >> n >> m >> C;
    vector<pair<int, int> > v[30001]; 
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a>> b>> c;
        v[a].push_back({c, b});// 시간, 도착지
    }
    priority_queue< pair<int, int> > pq;
    //c도시부터 출발
    int dist[30001];
    fill(dist, dist+30001, INF);

    pq.push({0, C});
    dist[C] = 0;
    
    while(!pq.empty()){
        int d = -pq.top().first;
        int w = pq.top().second;
        pq.pop();
        if(dist[w]< d ) continue; // 이전에 처리한 노드인지 확인.
        for(int i=0; i<v[w].size(); i++){
            int cost = d + v[w][i].first; //c++에서는 pq가 맥스힙 이기때문에 -를 붙여 작은값 부터 뽑을수있게 변경
            if(cost < dist[v[w][i].second]) {
                dist[v[w][i].second] = cost;
                pq.push({ -cost, v[w][i].second });
            }
            
        }
    }
    int cnt=0, time=0;
    for(int i=1; i<=n; i++){
        if(dist[i] != INF)
        {
            cnt++;
            time = max(time , dist[i]);
        }
    }   

    cout << cnt -1 << " " << time << endl;


    return 0;
}