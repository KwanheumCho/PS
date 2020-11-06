#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N, M;

struct Node{
    int minv;
    int maxv;
};

Node seg_tree[100000*4];
int arr[100000+1];
//int node_number = 0;
Node Make_tree(int node, int start, int end){
    if(start==end){
        seg_tree[node].minv = arr[start];
        seg_tree[node].maxv = arr[start];
        //if(node > node_number) node_number = node;
        return seg_tree[node];
    }

    int mid = (start+end)/2;
    Node left_result = Make_tree(node*2, start, mid);
    Node right_result = Make_tree(node*2+1, mid+1, end);
    seg_tree[node].minv = min(left_result.minv, right_result.minv);
    seg_tree[node].maxv = max(left_result.maxv, right_result.maxv);
    
    
    return seg_tree[node];
}

Node find(int node, int start, int end, int left, int right){
    if(left > end || right < start) return {-1,-1}; //left,right가 구해야하는 범위
    if(left <= start && end <= right){
        //cout <<"here: "<<node<< " "<< seg_tree[node].minv << " " << seg_tree[node].maxv<<endl;
        return seg_tree[node];
    } 

    int mid = (start+end)/2;
    Node left_result = find(node*2, start, mid, left, right);
    Node right_result = find(node*2+1, mid+1, end, left, right);
    if(left_result.minv != -1 && right_result.minv != -1){
        return {min(left_result.minv, right_result.minv) ,max(left_result.maxv, right_result.maxv) };
    }
    else if(right_result.minv == -1){
        return left_result;
    }
    else if(left_result.minv == -1){
        return right_result;
    }
}



int main(void){
    //int N, M;
    cin >> N >> M;
    //int* arr = new int[N+1];
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    vector<Node> answer;
    Make_tree(1, 1, N);
    //cout << seg_tree[9].minv << " " << seg_tree[9].maxv << endl;
    //cout << node_number << endl;
    for(int i=0; i< M; i++){
        int x , y;
        cin >> x>> y;
        Node result = find(1, 1, N, x, y);
        answer.push_back(result);
    }
    for(int i=0; i<answer.size(); i++){
        cout << answer[i].minv << " " << answer[i].maxv << '\n';
    }
}