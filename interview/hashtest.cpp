#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
struct pos{
    int x;
    int y;
};

bool compare(pos a, pos b){
    return a.x > b.x;
}

int main(void){
    map<string, vector<pos>> B;
    B["hello"].push_back({2, 5});
    B["hello"].push_back({3, 9});
    B["hello"].push_back({1, 8});
    B["hello"].push_back({4, 12});
    map<string, vector<pos>>::iterator iter;
    for(iter=B.begin(); iter!=B.end(); iter++){
        sort(iter->second.begin(), iter->second.end(), compare);
    }
    /*
    for(auto &k : B){
        sort(k.second.begin(), k.second.end(),compare);
    }
    */
    for(int i=0; i< B["hello"].size();i++){
        cout << B["hello"][i].x << B["hello"][i].y<<endl;
    }
    return 0;
}