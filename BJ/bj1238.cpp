#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
#define INF 1000000000
int N, M, X;
vector< pair<int, int> > connect [1001];
int dist[1001];
void func_dij( int from ){
    dist[from] = 0; //시작점이라서 0
    priority_queue< pair<int,int> , vector< pair<int, int> >, greater< pair<int, int> > > q;
    q.push( make_pair(0, from)); // pair(거리 , 인덱스)
    
    while(!q.empty()){
        int from_x = q.top().second;
        int dist_x = q.top().first;//q에선 first는 거리
        q.pop();
        for( int i=0; i<connect[from_x].size(); i++){
            int index = connect[from_x][i].first; // connect에선 first가 index
            int distance = connect[from_x][i].second;
            if(dist[index] > distance + dist[from_x]){
                dist[index] = distance + dist[from_x];
                q.push( make_pair(dist[index], index));
            } // dist[index]의 초기값 inf.   
        }
    }
}


int main(void){
    cin >> N >> M >> X;
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a>> b>> c;
        connect[a].push_back(make_pair(b,c)); // b: 목적지 c:distance
    }
    int* arr = new int[N+1];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) dist[j] =INF;
        func_dij(i);
        arr[i] = dist[X]; // i to X의 최소값.
    }
    for(int i=1; i<=N; i++) dist[i] =INF;
    func_dij(X); // X to ~의 최소값. dist에 저장
    int answer = 0;
    for(int i=1; i<=N; i++){
        if(answer < arr[i] + dist[i]) answer = arr[i] + dist[i];
    }
    cout << answer <<endl;

    return 0;
}