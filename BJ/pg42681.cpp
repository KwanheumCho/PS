#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int find_parent(int* arr, int x){
    if(arr[x] != x){
        arr[x] = find_parent(arr, arr[x]);
    }
    return arr[x]; // 경로 압축
}

void union_(int* arr, int a, int b){
    a = find_parent(arr, a);
    b = find_parent(arr, b);
    if(a<b) arr[b] = a;
    else if(a>b) arr[a] = b;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    //크루스칼로 해결.
    vector< pair<int, pair<int, int> > > v;
    for(int i=0; i<costs.size(); i++){
        v.push_back({costs[i][2] , {costs[i][0], costs[i][1]}});
    }
    sort(v.begin(), v.end());
    int* parent = new int[n];
    for(int i=0; i<n; i++) parent[i] = i;
    for(int i=0; i<v.size(); i++){
        int cost = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;
        if(find_parent(parent, a) != find_parent(parent, b)){
            union_(parent, a, b);
            answer += cost;
        }
    }
    /*
    vector<pair<int, int > > v [n+1];
    for(int i=0; i<costs.size(); i++){
        int from = costs[i][0];
        int to = costs[i][1];
        int cost = costs[i][2];
        v[from].push_back({to, cost});
        v[to].push_back({from, cost});
    }
    //다익스트라 사용 , priority queue
    int *arr = new int[n+1];
    for(int i=0; i<n; i++) arr[i] = INF; //초기 값 설정
    priority_queue< pair<int, pair<int,int> > > pq; // dist , number, cost;
    arr[0] = 0;
    pq.push( {0, {0,0}}); //dist, number;
    while(!pq.empty()){
        int dist = - pq.top().first;
        int number = pq.top().second.first;
        if( arr[number] < dist) continue;
        else{
            answer += pq.top().second.second;;
        }
        pq.pop();
        for(int i=0; i<v[number].size(); i++){
            int node = v[number][i].first;
            int cost = v[number][i].second;
            if( dist+cost < arr[node]){
                arr[node] = dist+cost;
                //answer += cost;
                pq.push({-(dist+cost), {node, cost}});
            }
        }
    }
    */
    
    
    return answer;
}