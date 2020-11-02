#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define MAX_SIZE 200001

map<string, int> m;
int parent[MAX_SIZE];
int node_number[MAX_SIZE];
int node_rank[MAX_SIZE];

int find_func(int x){
    if(x == parent[x]) return x;
    else return parent[x] = find_func(parent[x]);
}
void union_func(int x, int y){
    x = find_func(x);
    y = find_func(y);
    if(x==y) return;
    else{
        if(node_rank[x] < node_rank[y]){
            parent[x] = y;
            node_number[y] += node_number[x];
        }
        else{
            parent[y] = x;
            node_number[x] += node_number[y];
            if(node_rank[x] == node_rank[y]) node_rank[x]++;
        }  
    } 
}


int main(void){
    
    int T, F;
    cin >> T;
    vector<int> result;
    
    for(int i=0; i<T; i++){
        //For : test case
        cin >> F;
        for(int i=0; i<=MAX_SIZE;i++){
            parent[i] = i;
            node_number[i] = 1;
            node_rank[i] = 1;
        }

        int cnt = 1;
        for(int j=0; j<F; j++){
            //friend relationship < 100000
            string a, b;
            cin >> a >> b;
            if(m[a]==0) m[a] = cnt++;
            if(m[b]==0) m[b] = cnt++;
            //cout << m[a] <<" " << m[b]<<endl;
            union_func(m[a], m[b]);
            //cout<<node_number[find_func(m[a])]<<endl;
            result.push_back(node_number[find_func(m[a])]);
        }
        m.clear();
    }
    
    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }
    
    //cout <<m["jason"]<<endl;
    return 0;
}