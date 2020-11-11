#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int map_[26][26];
int chk_[26][26] = {false,};
int N;
int dx[4]= {1, 0, -1, 0};
int dy[4]= {0, 1, 0, -1};
int find_func(int r, int c){
    int number = 0;
    queue< pair<int, int> > q;
    q.push( make_pair(r,c) );
    chk_[r][c] = true;
    number++;
    
    while(!q.empty()){
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r+dy[i];
            int nc = c+dx[i];
            if( nr>=0 && nr<N && nc>=0 && nc<N){
                if(map_[nr][nc]==1 && chk_[nr][nc]==false){
                    chk_[nr][nc] = true;
                    number++;
                    q.push( make_pair(nr,nc));
                }
            }
        }
    } //while
    //cout << "cnt: "<<cnt<<endl;
    return number;
}

int main(void){
    cin >> N;
    for(int i=0; i<N; i++){
        string x;
        cin >> x;
        for(int j=0; j<x.size(); j++){
            map_[i][j] = int(x[j]-'0');
        }
    }
    vector<int> answer;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map_[i][j]==1 && chk_[i][j]==false){
                answer.push_back(find_func(i, j));
            }
        }
    }
    cout << answer.size() << endl;
    sort(answer.begin(), answer.end());
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << endl;
    }

    return 0;
}