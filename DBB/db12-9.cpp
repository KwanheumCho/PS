//프로그래머스
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int func_num(int count){
    if(count >=1000) return 4;
    else if(count >=100) return 3;
    else if(count >=10) return 2;
    else if(count >=2) return 1;
    else return 0;
}

int solution(string s) {
    int answer = 1000;
    int cut_size;
    if(s.size()==1) return 1;
    for(int i=0; i< s.size()/2; i++){
        cut_size = i+1;
        string before = "";
        string after = "";
        bool compare_start = false;
        int counter = 1;
        string test ="";
        int tmp_answer = 0;
        for(int j=0; j<s.size(); j++){
            //비교 string 생성
            if(before.size() < cut_size){
                before+=s[j];
            }
            else if(after.size() < cut_size){
                after+=s[j];
                if(after.size()==cut_size || j==s.size()-1) compare_start = true;
            }
            if(compare_start){
                if(before==after){
                    counter++;
                }
                else{
                    tmp_answer+= func_num(counter) + before.size();
                    //test += to_string(counter) + before;
                    counter = 1;
                }
            before = after;
            after = "";
            if(j==s.size()-1){
                tmp_answer+= func_num(counter) + before.size();
                //test += to_string(counter) + before;
            }
            compare_start = false;}
        }// for j
        //cout << "i: "<<i<< "tmp_answer: "<<tmp_answer<<" test: "<<test << endl;
        if(tmp_answer < answer) answer = tmp_answer;
    }//cutsize
    
    return answer;
}