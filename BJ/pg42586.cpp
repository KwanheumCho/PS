#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    int day = 0;
    while(idx< progresses.size()){
        int cnt = 0;
        int now_p = progresses[idx];
        int now_s = speeds[idx];
        while(true){
            if(now_p + day*now_s >= 100) break;
            day++;
        }
        while(idx < progresses.size()){
            if( progresses[idx] + day* speeds[idx] >= 100){
                idx++;
                cnt++;
                //cout << idx << " " << cnt << endl;
            }
            else {
                break;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}