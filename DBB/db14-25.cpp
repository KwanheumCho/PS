#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(pair<float,int> a, pair<float,int> b){
    if(a.first != b.first){
        return a.first>b.first;
    }
    else{
        return a.second < b.second;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int arr_[502] = {0,};
    for(int i=0; i<stages.size(); i++){
        arr_[stages[i]]++;
    }
    
    int total = stages.size();
    vector<pair<float , int> > tmp;
    for(int i=1; i<=N; i++){
        float fail;
        if(total==0) fail = 0.0;
        else fail = (float)arr_[i] / (float)total; 
        tmp.push_back({fail, i});
        //cout << "fail: "<<fail<<" i: "<< i << endl;
        total -= arr_[i];
    }
    
    sort(tmp.begin(), tmp.end(), comp);
    for(int i=0; i<tmp.size(); i++){
        answer.push_back(tmp[i].second);
    }
    return answer;
}