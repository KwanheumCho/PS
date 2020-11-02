#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MAX_SIZE 1000000

int root[MAX_SIZE+1];
int level[MAX_SIZE+1];
int find_func(int x){
    if(root[x] == x) return x;
    else{
        return root[x] = find_func(root[x]);
    }
}

void union_func(int x, int y){
    int a = find_func(x);
    int b = find_func(y);
    if(a==b) return;
    else{
        if(level[a] < level[b]) root[a] = b;
        else{
            root[b] = a;
            if(level[a]==level[b]) level[a]++;
        }
    }
}


int main(void){

    int n, m;
    cin >> n >> m;
    //int* root = new int[n+1];
    for(int i=0; i<=n; i++){
        root[i] = i;
        level[i] = 1;
    }
    
    vector<string> result;
    for(int i=0; i< m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==0) union_func(b, c);
        else{
            if(find_func(b)==find_func(c)) result.push_back("YES");
            else result.push_back("NO");
        }
    }

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<'\n';
    }
    
    return 0;
}