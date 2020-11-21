#include <iostream>
#include <string>
using namespace std;

int main(void){
    string x;
    int answer = 0;
    cin >> x;
    //1이나 0이면 곱하면 손해.
    for(int i=0; i<x.size(); i++){
        int target = int(x[i]-'0');
        if(answer==0 || target == 0 || target ==1 ) answer += target;
        else{
            answer *= target;
        }
    }
    cout << answer << endl;

    return 0;
}