#include <iostream>
using namespace std;

int main(void){
    int N, K;
    cin >> N >> K;
    int answer = 0;
    while (true){
        if(N%K ==0){
            N /= K;
            answer ++;
        }
        else{
            N--;
            answer ++;
        }
        if(N==1) break;
    }
    cout << answer << endl;
}