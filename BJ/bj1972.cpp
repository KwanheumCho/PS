#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void){
    int N;
    //priority_queue<int> q;
    priority_queue< int, vector<int>, greater<int>> q;
    cin >> N;
    vector<int> answer;
    for(int i=0; i<N; i++){
        int input;
        cin >> input;
        if(input == 0){
            if(!q.empty()){
                //cout << q.top();
                answer.push_back(q.top());
                q.pop();
            }
            else{
                //cout << 0 << endl;
                answer.push_back(0);
            }
        }
        else{
            q.push(input);
        }
    }
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << '\n';
    }


    return 0;
}