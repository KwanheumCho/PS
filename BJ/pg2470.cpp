#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool comp(pair<float,int> A, pair<float, int> B){
    if(A.first > B.first) return true;
    else if(A.first == B.first) return A.second < B.second;
    else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int* arr = new int[N+1];
    for(int i=0; i<=N; i++) arr[i] = 0;
    int total = stages.size();
    for(int i=0; i<stages.size(); i++){
        int num = stages[i];
        arr[num]++;
    }
    
    int* arr2 = new int[N+1];
    arr2[1] = total;
    int before = arr[1]; // 1에 남아있는사람
    for(int i=2; i<=N; i++){
        arr2[i] = total - before;
        before += arr[i];
    }
    //실패율
    vector<pair<float, int> > v;
    for(int i=1; i<=N; i++){
        //cout << arr[i] << " " << arr2[i] << endl;
        //cout << (float)arr[i]/(float)arr2[i] << endl;
        float fail;
        if(arr2[i] == 0 ) fail = 0.0;
        else fail = (float)arr[i]/(float)arr2[i];
        v.push_back({fail, i});
    }
    sort(v.begin(), v.end(), comp);
    for(int i=0; i<v.size(); i++){
        answer.push_back(v[i].second);
    }
    return answer;
}