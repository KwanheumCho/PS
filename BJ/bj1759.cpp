#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> v;
vector<string> answer;
int l , c;

bool mo_chk(char x){
    if(x=='a' || x=='i'||x=='o'||x=='e'||x=='u'){
        return true;
    }
    else return false;
}

void func_(int start, int mo, int za, vector<char> tmp){
    if(mo>=1 && za>=2 && mo+za==l){
        sort(tmp.begin(), tmp.end());
        string s = "";
        for(int i=0; i<tmp.size(); i++){
            s += tmp[i];
        }
        answer.push_back(s);
        return;
    }
    for(int i=start; i<v.size(); i++){
        tmp.push_back(v[i]);
        if(mo_chk(v[i])) func_( i+1, mo+1, za, tmp);
        else func_(i+1, mo, za+1, tmp);
        tmp.pop_back();
    }
    return;
}
int main(void){

    cin >> l >> c;
    //서로다른 l개의 알파벳 소문자로 구성.
    //c개의 알파벳이 주어짐
    //최소 한개의 모음과 최소 두개의 자음
    //모음 : a e i o u
    for(int i=0; i<c; i++){
        char x;
        cin >> x;
        v.push_back(x);
    }
    vector<char> tmp;
    func_(0 , 0, 0, tmp);
    sort(answer.begin(), answer.end());
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << '\n';
    }
}