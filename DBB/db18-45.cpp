#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define INF 1e9

int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int ii=0; ii<t; ii++){
        int n;
        cin >> n;
        int arr[501];
        int graph[501][501];
        for(int i=0;i<501;i++) fill(graph[i], graph[i]+501, 0); // 처음에 그래프를 0으로 초기화 안해주면 dummy 값에 의해 결과가 달라질수도...
        int degree[501] = {0, };
        for(int k=1; k<=n; k++){
            cin >> arr[k]; // 1~n
        }
        for(int i=1; i<n; i++){
            for(int j=i+1; j<=n; j++){
                graph[arr[i]][arr[j]] = 1;
                degree[ arr[j] ]++;
            }
        }
        
        int m;
        cin >> m;
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            if(graph[a][b]==1){
                graph[b][a] = 1;
                graph[a][b] = 0;
                degree[a]++;
                degree[b]--;
            }
            else{
                graph[b][a] = 0;
                graph[a][b] = 1;
                degree[a]--;
                degree[b]++;
            }
        }
        queue<int> q;
        for(int i=1; i<=n; i++){
            if(degree[i] == 0)
            q.push(i);
        }
        bool flag = false;
        //bool cycle = false;
        vector<int> result;
        while(!q.empty()){    
            if(q.size()>=2){
                flag = true;
                break;
            }
            int now = q.front();
            result.push_back(now);
            q.pop();
            for(int i=1; i<=n; i++){
                if(graph[now][i]==1){
                    degree[i]--;
                    if(degree[i]==0) {
                        q.push(i);
                        }
                }
            }
        }
        if(flag) cout << "?" << endl; // 경우가 2가지이상인것.
        else if( result.size()!=n ) cout << "IMPOSSIBLE"<<endl; //싸이클이 있어서 결과가 n개가 안된 경우
        else{
            for(int i=0; i<result.size(); i++){
                cout << result[i]<<" ";
            }
            cout << endl;
        }


        
        



    }//t
}