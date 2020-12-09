#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define INF 1e9

int main(void){
    int n;
    cin >> n;
    vector<int> v[501];
    int* node_time = new int[n+1];
    pair<int, int>* degree = new pair<int, int>[n+1];
    for(int i=1; i<=n; i++){
        int time;
        cin >> time;
        node_time[i] = time;
        int before =0, cnt=0;
        while(before != -1){
            cin >> before;
            if(before!=-1){
                cnt++;
                v[before].push_back(i);
            } 
        }
        if(cnt!=0) degree[i] = {cnt, 0};
        else degree[i] = {cnt, time};
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i].first == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int now = q.front();
        int cost = degree[now].second;
        q.pop();
        for(int j=0; j<v[now].size(); j++){
            int connect = v[now][j];
            degree[connect].first -=1;
            degree[connect].second = max(degree[connect].second, cost);
            if(degree[connect].first == 0){
                degree[connect].second += node_time[connect]; // 차수가 0일때 자기 소요시간도 추가.
                q.push(connect);
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << degree[i].second << endl;
    }
}