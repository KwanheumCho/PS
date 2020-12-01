#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void){
    int N, C;
    cin >> N >> C;
    vector<int> v;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int start = 1;
    int end = 1000000000-1;
    int answer;
    while(start <= end){
        int mid = (start+end)/2;
        //cout << mid << endl;
        //bool flag = false;
        int base = v[0];
        int cnt = 1;
        for(int i=1; i<N; i++){
            if(v[i] >= base + mid){
                cnt++;
                base = v[i];
            }
        }
        //cout << "cnt: "<<cnt << endl;
        if(cnt >= C){ // 현재 mid 값으로 가능!
            start = mid+1;
            answer = mid;
            //cout <<"here: "<< answer << endl;
        }
        else{
            end = mid-1;
        }
    }
    cout <<answer << endl;


}