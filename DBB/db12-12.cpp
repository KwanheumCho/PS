//프로그래머스
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
map< pair<int, int> , int > m;

bool possible_chk(int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(m[{i,j}] == 2){
                if(i!=0 && !(m[{i-1,j}] == 2 || m[{i-1,j}] ==5) &&(m[{i,j-1}] <=2)) {return false;}
            }
            else if(m[{i,j}] >= 3){
                if((m[{i-1,j}]==2 || m[{i-1,j}] == 5) || (m[{i-1,j+1}]==2 || m[{i-1,j+1}] == 5) || ((m[{i,j-1}]==3 ||m[{i,j-1}]==5) && (m[{i,j+1}]==3 || m[{i,j+1}]==5))){
                }
                   else {return false;}
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    //보는 한쪽끝이 기둥 or 양쪽 끝이 다른보와 연결
    int arr[101][101];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            arr[i][j] = -1;
        }
    }
    for(int i=0; i<build_frame.size(); i++){
        int col = build_frame[i][0];
        int row = build_frame[i][1];
        int what = build_frame[i][2]; // 0이면 기둥 1이면 보
        int how = build_frame[i][3]; // 0이면 삭제 1이면 설치
        bool flag;
        if(how==1){
            if(what == 0){//기둥 설치 m[{row,col}] = 2;
                    m[{row,col}] += 2;
                    flag = possible_chk(n);
                    if(!flag) m[{row,col}] -= 2;
            }
            else{//보 설치 m[{row,col}] = 3;
                    m[{row,col}] += 3;
                      flag = possible_chk(n);
                    if(!flag) m[{row,col}] -= 3;
            }
        }
        
        else{//제거
            if(what==0){
                m[{row,col}] -= 2;  
                flag = possible_chk(n);
                if(!flag) m[{row,col}] += 2;
            }
            else{
                m[{row,col}] -= 3;
                flag = possible_chk(n);
                if(!flag) m[{row,col}] += 3;
            }
        }
    }
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            vector<int> tmp;
            tmp.push_back(j); //j가 x좌표
            tmp.push_back(i);
            if(m[make_pair(i,j)]==5) {
                //cout << j << " " <<i<< " " <<m[make_pair(i,j)]-5 <<endl;
                //cout << j << " " <<i<< " " <<m[make_pair(i,j)]-4 <<endl;
                tmp.push_back(m[make_pair(i,j)]-5);
                answer.push_back(tmp);
                tmp.pop_back();
                tmp.push_back(m[make_pair(i,j)]-4);
                answer.push_back(tmp);
            }
            else if(m[make_pair(i,j)]>=2){
                tmp.push_back(m[make_pair(i,j)]-2);
                //cout << j << " " <<i<< " " <<m[make_pair(i,j)]-2 <<endl;
                answer.push_back(tmp);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}