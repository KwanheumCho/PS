#include <iostream>
#include <string>
#include <vector>
using namespace std;
int T;
int main(void){
    cin >> T;
    vector<string> answer;
    for(int i=0; i<T; i++){
        //case1:  100+1+ => 10 0~00 1~11
        //case2:  01
        string x;
        cin >> x;
        int j=0;
        bool total_flag = true;
        while(j < x.size()){
            if(x[j]=='0'){
                if(j==x.size()-1){
                    answer.push_back("NO");
                    total_flag = false;
                    break;
                }
                else if(x[j+1] != '1'){
                    answer.push_back("NO");
                    total_flag = false;
                    break;
                }
                j+=2; 
            }
            if(x[j]=='1'){
                if(j>x.size()-4){//남은 공간이 3칸보다 적다면
                    answer.push_back("NO");
                    total_flag = false;
                    break;
                }
                else if(x[j+1] !='0' || x[j+2] != '0'){
                    answer.push_back("NO");
                    total_flag = false;
                    break;
                }
                //j+2부터 0의갯수는 1이상~??
                //0이 끝난지점부터 1의 갯수는 1이상~??
                // 10001 101
                // 
                // 10001 1001
                int k = j+2;
                int cnt = 0;
                bool flag = false;
                while(k <x.size()){
                    if(x[k]=='0'){
                        flag = false;
                        k++;
                    }
                    if(x[k]=='1'){
                        cnt++;
                        flag = true; //1001 의 case가 성공되었는지 확인
                        if(k+1<x.size()){
                            if(x[k+1]=='1') {
                                k++;
                                }
                            else{
                                if(cnt==1){ //cnt가 1이면 1001001의 경우와같이 중간에 1이하나밖에없어서 k를 1증가시켜주고 새로운 케이스 시작
                                    k++;
                                    break;
                                }
                                else{
                                    if(k+2<x.size()){
                                        if(x[k+2]=='0'){
                                            break;
                                        }
                                        else{
                                            k++;
                                            break;
                                        }
                                    }
                                    else {
                                        break;
                                        }
                                }
                            }
                        }
                        k++;
                    }
                }
                j = k;
                if(!flag){
                    answer.push_back("NO");
                    total_flag = false; // 10000과 같은경우를 막기위한 flag
                    break;
                }
            }
        }// while
        if(j>=x.size() && total_flag) answer.push_back("YES");
    }// Test case T
    for(int a=0; a< answer.size(); a++){
        cout << answer[a] << endl;
    }
}