#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;

    map<string, int> m;
    vector<string> result;
    string name;
    for(int i=0; i<N; i++){
        //string name;
        cin >> name;
        m[name]++;
    }
    for(int i=0; i<M; i++){
        cin >> name;
        if(m[name]==1) result.push_back(name);  
    }
    sort(result.begin(), result.end());
    cout << result.size() <<endl;
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
    return 0;
}