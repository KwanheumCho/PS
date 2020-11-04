#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int* arr = new int[N];
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    //기준 왼쪽 최대값이 현재 값보다 작으면? 0
    //크면? for문돌면서 체크? => time over
    //stack활용해보자
    //수신탑이 될 가능성이 있는 후보들만 stack에 남겨놓기!

    vector<int> answer;
    stack< pair<int, int> > s;
    pair<int, int> cmp;
    for(int i=0; i<N; i++){
        int cur = arr[i];
        if(s.empty()){
            answer.push_back(0);
            s.push( make_pair( cur , i+1)); //second is index
        }
        else{
            while(!s.empty()){
                cmp = s.top();
                if(cmp.first > cur){
                    answer.push_back(cmp.second);
                    s.push( make_pair( cur , i+1));
                    break;
                }
                else{
                    s.pop();
                }
            }
            //stack에 모든 값이 다 작을때
            if(s.empty()){
                answer.push_back(0);
                s.push( make_pair( cur , i+1));
            }
        }
    }
    for(int k=0; k<answer.size(); k++){
        cout << answer[k] << ' ';
    }

    return 0;
}