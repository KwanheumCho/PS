#include <string>
#include <vector>
#define MAX_VALUE 100000000
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    // 3 1 2,,, 한바퀴돌면 3초
    // 2 0 1
    int cycle=0;
    int arr[MAX_VALUE+1] = {0,};
    for(int i=0; i<food_times.size(); i++){
        arr[food_times[i]]++;
        if(food_times[i]>0) cycle++;
    }
    // K초 후에 몇번음식을 먹으면되나?
    int i=0;
    while(true){
        if(k >= cycle){
           i++;
            k-=cycle;
            cycle -= arr[i]; // 그 회전에 빠지는 갯수를 싸이클에서 뺌.
        }
        else{
            break;
        }
    }
    for(int j=0; j<food_times.size(); j++){
        if(food_times[j] - i > 0 ){
            if(k>0){
              k--;
            } 
            else if(k==0) {
                answer = j+1;
                break;
            }
        } 
    }
    if(answer ==0) answer = -1;
    return answer;
}