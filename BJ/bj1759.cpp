#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> input;
vector<string> tmp;
int L;
int C;
void make_answer(string a, int cnt, int m, int j){
    //cout << a << cnt <<" "<< m<<" " << j <<endl;
    
    if(m+j==L){
        if(m>=1 && j>=2){
            tmp.push_back(a);
            //cout << a << endl;
            return;
        }
        else return;
    }
    if(cnt >= C){
        return;
    }
    

    for(int i=cnt; i<input.size(); i++){
        string w = input[i];
        if(w=="a" || w=="e" || w=="i"|| w=="o"||w=="u") make_answer(a+w, i+1, m+1, j );
        else make_answer(a+w, i+1, m, j+1 );
    }
}

int main(void){
    cin >> L >> C; // L, C >=3
    for(int i=0; i<C; i++){
        string tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    sort(input.begin(), input.end());
    //최소 한개의 모음과 두개의 자음이 있어야해
    //서로다른 L개의 알파벳으로 구성
    make_answer("", 0, 0, 0);
    sort(tmp.begin(), tmp.end());
    
    for(int k=0; k<tmp.size(); k++){
        cout << tmp[k] << endl;
    }
}