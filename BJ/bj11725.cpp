#include <iostream>
#include <vector>
using namespace std;

int arr[100000] = {0,};
vector<int> tree[100001];
void func(int cnt){
    if(tree[cnt].size()==0) return;
    for(int i=0; i< tree[cnt].size(); i++){
        int index = tree[cnt][i];
        //cout << cnt <<" "<<index << endl;
        if(arr[index]==0){
            arr[index] = cnt;
            func(index);
        }
    }
}


int main(void){
    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    arr[1] = 1;
    func(1);
    for(int i=2; i<=N; i++){
        cout << arr[i] << '\n';
    }

    return 0;
}