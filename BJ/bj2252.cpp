#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    vector<int>* graph = new vector<int>[N+1];
    int* connect_number = new int[N+1];
    for(int i=1; i<=N; i++){
        connect_number[i] = 0;
    }

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        connect_number[b]++;
    }
    queue<int> q;
    //입력간선이 없는 경우 q에 삽입
    for(int i=1; i<=N; i++){
        if(connect_number[i]==0){
            q.push(i);
        }
    }
    vector<int> result;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        result.push_back(x);
        if(graph[x].size()>0){
            for(int i=0; i<graph[x].size();i++){
                if(--connect_number[graph[x][i]]==0){
                    q.push(graph[x][i]);
                }
            }
        }        
    }
    for(int i=0; i<result.size(); i++){
        cout<<result[i] << " ";
    }

    return 0;
}