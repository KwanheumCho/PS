#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    string x;
    cin >> x;
    vector<char> alpha;
    vector<char> number;
    for(int i=0; i<x.size(); i++){
        if(x[i]>='0' && x[i]<='9'){
            number.push_back(x[i]);
        }
        else{
            alpha.push_back(x[i]);
        }
    }
    sort(number.begin(), number.end());
    sort(alpha.begin(), alpha.end());
    string answer = "";
    int answer2 = 0;
    for(int i=0; i<alpha.size(); i++){
        answer += alpha[i];
    }
    for(int i=0; i<number.size(); i++){
        answer2 += int(number[i]-'0');
    }
    cout << answer << answer2<< endl;
}