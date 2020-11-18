#include <iostream>
#include <string>
using namespace std;
int N;
int answer = 0;
bool group_chk[26];

bool func_(string x){
    int i=0;
    while(i<x.size()){
        char C = x[i];
        if(!group_chk[C-'a']){
            while(x[i]==x[i+1]){
                i++;
            }
            group_chk[C-'a'] = true;
        }
        else{
            return false;
        }
        i++;
    }
    return true;
}

int main(void){
    cin >> N;
    for(int i=0; i<N; i++){
        string input;
        cin >> input;
        //단어 체크 함수
        for(int k=0; k<26; k++) group_chk[k] = false;
        if(func_(input)) answer ++;
    }
    cout << answer << endl;
}