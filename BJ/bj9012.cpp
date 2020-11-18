#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int T;

int main(void){
    cin >> T;
    vector<string> answer;
    for(int i=0; i<T; i++){
        stack<char> s;
        string x;
        cin >> x;
        for(int j=0; j<x.size(); j++){
            s.push(x[j]);
        }
        bool flag = false;
        int cnt = 0;
        while(!s.empty()){
            if(s.top()=='('){
                if(cnt>0){
                    cnt--;
                }
                else{
                    flag = true;
                    break;
                }    
            }
            else{
                cnt++;
            }
            s.pop();
        }
        if(flag || cnt>0) answer.push_back("NO");
        else  answer.push_back("YES");
    }//Test case for//
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<endl;
    }
}