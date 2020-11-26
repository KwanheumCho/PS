#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//교재 해설..
// idea : 1. 순열의 모든경우를 다 체크 한다.
//        2. 원의 크기를 두배로 늘려서 index계산을 간편하게 한다.
//        ex(0 ~ length-1) or (length-1 ~ 2length -2)
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 10000000;
    int length = weak.size();
    for(int i=0; i<length; i++){
        weak.push_back(weak[i]+n);
    } // 길이 2배로 늘려서 원형을 일자로 변경
    for(int start=0; start<length; start++){
        do{
            int cnt = 1;
            int pos = weak[start]+ dist[cnt-1];
            for(int index= start; index<start+length; index++){
                if(pos < weak[index]){
                    cnt+= 1;
                    if(cnt > dist.size()) break;
                    pos = weak[index]+dist[cnt-1];
                }
            }
            answer = min(answer, cnt);
        }while(next_permutation(dist.begin(),dist.end()));
    }
    if (answer > dist.size()) return -1;
    return answer;
}


/*
내풀이 => 3,4,13 시간초과 ㅠㅠ
bool answer_flag = false;
int target;
void func_(int n, int start, vector<int> weak, bool* circle, vector<int> tmp, int cnt){
    if(cnt==target) {
        answer_flag = true;
        return;
    }
    if(tmp.size() ==0) return;
    int length = tmp[tmp.size()-1];
    tmp.pop_back();
    bool* before_circle = new bool[n];
    for(int k=0; k<n; k++) {before_circle[k] = circle[k];     }
    
    for(int a=start; a<weak.size(); a++){
        int i = weak[a];
        {
            int x = 0;
             for(int j=0; j<=length; j++){
                int idx = (i+j)%n;
                 if(circle[idx]){//취약지점이면
                     x++;
                     circle[idx]=false;
                 }
             }
            func_(n, a+x, weak,  circle, tmp, cnt+x );
             for(int k=0; k<n; k++) {
                    circle[k] = before_circle[k]; }
        }
    }//for i
    return;
}//func_



int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 10000000;
    int friends = dist.size();
    target = weak.size();
    bool* circle = new bool[n]{false,};
    
    for(int i=0; i<weak.size(); i++){
        circle[weak[i]] = true; // true : means 수리필요한 곳
    }
    
    //점검을 최소로하기 위해서는 , 많이돌아다니는 애들이 체크를 해야돼.
    
    sort(dist.begin(), dist.end());
    for(int i=0; i<friends; i++){
        vector<int> tmp;
        for(int j=0; j<=i; j++){
            tmp.push_back(dist[friends-1-j]);
        }
        do{ answer_flag = false;
            func_(n, 0, weak, circle, tmp, 0);
            if(answer_flag) {
                answer = min(answer,i+1);
                break;
            }
        }while(prev_permutation(tmp.begin(), tmp.end()));
        if(answer_flag) break;
    }
    
    if(answer == 10000000) return -1;
    else return answer;
}
*/