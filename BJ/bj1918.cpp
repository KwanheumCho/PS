#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main(void){
    string input;
    cin >> input;
    string answer ="";
    stack<char> s;
    for(int i=0; i<input.size(); i++){
        //cout << answer << endl;
        char x = input[i];
        if(x!='+' && x!='-' && x!='*' && x!='/' && x!='(' && x!=')'){
            answer += x;
        }
        else if(x=='+' || x=='-'){
            while(!s.empty()){
                if(s.top()!='('){
                    answer += s.top();
                    s.pop();
                }
                else{
                    //s.pop();
                    break;
                }
            }
            s.push(x);
        }
        else if(x=='*' || x=='/'){
            //cout<<"nda"<<endl;
            if(!s.empty()){
                if(s.top() =='*' || s.top() == '/'){
                //cout<<"aaaa"<<endl;
                answer += s.top();
                s.pop();
                }
                s.push(x);
            }
            else s.push(x);
        }
        else if(x=='('){
            s.push(x);
        }
        else if(x==')'){
            while(!s.empty()){
                if(s.top()!='('){
                    answer += s.top();
                    s.pop();
                }
                else{
                    s.pop();
                    break;
                }
            }
        }
    }
    while(!s.empty()){
        answer += s.top();
        s.pop();
    }
    cout << answer << endl;
    return 0;
}