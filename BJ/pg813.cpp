#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(int num) {
    int answer = 0;
    long long x = num;
    while(answer < 500){
        if(x == 1) break;
        if(x % 2 == 0) x/=2;
        else{
            x = 3*x + 1;
        }
        //cout << num << endl;
        answer++;
    }
    if(answer == 500) answer = -1;
    return answer;
}