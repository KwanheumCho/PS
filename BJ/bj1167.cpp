#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NODE 100001
using namespace std;
int V;
vector< pair<int, int> > tree[MAX_NODE];
int tmp_result = 0;
int tmp_node;
bool chk_[MAX_NODE] = {false, };

void func_(int x, int distance){
    if(distance > tmp_result){
        tmp_result = distance;
        tmp_node = x;
    }
    chk_[x] = true;
    for(int i=0; i<tree[x].size(); i++){//x노드에 연결된 다른 노드 반복문
        int node = tree[x][i].first;
        int dist = tree[x][i].second;
        if(chk_[node]==false) func_(node , distance+dist);
    }
}


int main(void){
    cin >> V;
    
    for(int i=0; i<V; i++){
        //번호는 1번~ V번
        int node_number;
        cin >> node_number;
        int next_node, dist;
        while(true){
            cin >> next_node;
            if(next_node == -1) break;
            else{
                cin >> dist;
                tree[i+1].push_back( make_pair(next_node, dist) );
            }
        }
    }
    int answer = 0;
    
    func_(1, 0);
    tmp_result = 0;
    //cout <<";"<< tmp_node << endl;
    for(int k=1; k<=V; k++) chk_[k] = false;
    func_(tmp_node, 0);
    answer = max(answer, tmp_result);
        
    
    cout << answer << endl;
    
}