#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000;

vector< pair<int, int> > V[1001];
int Dist[1001];

void Dijkstra(int start){

    priority_queue< pair<int, int> , vector< pair<int, int> > , greater<pair<int, int> > > PQ;
    Dist[start] = 0;
    PQ.push( make_pair( 0, start));
    while(!PQ.empty()){
        int cost = PQ.top().first;
        int cur = PQ.top().second;
        PQ.pop();
        for(int i=0; i< V[cur].size(); i++){
            int next = V[cur][i].first;
            int ncost = V[cur][i].second;
            if(Dist[next] > cost+ncost){
                Dist[next] = cost + ncost;
                PQ.push(make_pair(Dist[next], next));
            }
        }
    }
}

int main(void){
    int N, M, X;
    cin >> N >> M >> X;
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b>> c;
        V[a].push_back(make_pair(b,c));
        }
    int* tmp = new int[1001];
    
    for(int i=1; i<=N; i++){
        for(int i=1; i<=N; i++){
            Dist[i] = INF;
        }
        Dijkstra(i);
        tmp[i] = Dist[X]; // i->X로 가는 가장 짧은 경로를 tmp에 저장
    }
    for(int i=1; i<=N; i++){
        Dist[i] = INF;
    }
    for(int i=1; i<=N; i++){
        Dijkstra(X); // X -> i 로 가는 가장 짧은 경로가 Dist에 저장
    }
    int answer = 0;
    for(int i=1; i<=N; i++){
        tmp[i] += Dist[i];
        if(tmp[i] > answer) answer = tmp[i];
    }
    cout << answer << endl;



}