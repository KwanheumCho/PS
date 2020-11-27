#include <string>
#include <vector>
#include <stack>
using namespace std;

bool chk_(string p){
    stack<char> s;
    for(int i=0; i<p.size(); i++){
        if(p[i]=='(') s.push(p[i]);
        else{
            if(s.size()>0) s.pop();
            else return false;
        }
    }
    return true;
}

string func_(int start, string p){
    int left_cnt =0, right_cnt = 0;
    string u = "";
    for(int i=start; i<p.size(); i++){
        if(p[i]=='(') {
            left_cnt++;
        }
        else {
            right_cnt++;
        }
        u+=p[i];
        if(left_cnt == right_cnt){
            if(chk_(u)) return u+func_(i+1, p); //올바른 괄호 문자열;
            else{
                string tmp = "(";
                tmp+=func_(i+1,p);
                tmp+=")";
                for(int j=1; j<u.size()-1; j++){
                    if(u[j]=='(') tmp += ')';
                    else tmp += '(';
                }
                return tmp;
            }
        }
    }
    //빈문자열인경우?
    return u;
}

string solution(string p) {
    string answer = "";
    if(p.size() == 0) return answer;
    if(chk_(p)) return p;
    //균형잡힌 괄호 문자열 u, v 로 분리
    answer = func_(0, p);
    
    
    
    
    
    return answer;
}