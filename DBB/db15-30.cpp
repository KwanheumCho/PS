#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//프로그래머스

bool key_chk(string keyword){
    if(keyword[0] == '?') return false; //접두사 ????o
    else return true; //접미사 fro??
}



vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    //각 query에 대해 모든 word를 본다면 10만X10만 => 시간초과일것이다
    //word를 볼 때 log로 살펴본다면?
    vector<string> r_words;
    vector<string> w[10001];
    vector<string> r[10001];
    for(int i=0; i<words.size(); i++){
        string tmp = words[i];
        reverse(tmp.begin(), tmp.end());
        w[words[i].size()].push_back(words[i]);
        r[words[i].size()].push_back(tmp);
    }
    for(int i=0; i<10001; i++){
        sort(w[i].begin(), w[i].end());
        sort(r[i].begin(), r[i].end());
    }
    
    
    
    for(int i=0; i<queries.size(); i++){
        string keyword = queries[i];
        int size = keyword.size();
        int lower = -1;
        int upper = -1;
        int cnt = 0;
        if(keyword[0]=='?' && keyword[size-1]=='?'){
            cnt = w[size].size();
        }
        else{
            if(key_chk(keyword)){//words로 진행
                string a = "";
                string b = "";
                for(int j=0; j<keyword.size(); j++){
                    if(keyword[j]=='?') {
                        a+='a';
                        b+='z';
                    }
                    else{
                        a+=keyword[j];
                        b+=keyword[j];
                    }
                }
                lower = lower_bound(w[size].begin(), w[size].end(), a ) - w[size].begin();
                upper = upper_bound(w[size].begin(), w[size].end(), b ) - w[size].begin();
                //cout << a<<" " << b<<endl;
            }
            else{//r_words로 진행
                reverse(keyword.begin(), keyword.end());
                string a = "";
                string b = "";
                for(int j=0; j<keyword.size(); j++){
                    if(keyword[j]=='?') {
                        a+='a';
                        b+='z';
                    }
                    else{
                        a+=keyword[j];
                        b+=keyword[j];
                    }
                }
                lower = lower_bound(r[size].begin(), r[size].end(), a ) - r[size].begin();
                upper = upper_bound(r[size].begin(), r[size].end(), b ) - r[size].begin();
            }
            
                if(upper==-1 || lower==-1) cnt = 0;
                else{
                    cnt = upper - lower;
                }
        }
        
        answer.push_back(cnt);
        //cout <<keyword <<" "<< lower << " "<< upper<<" "<<cnt<<endl;
        
    }
    return answer;
}