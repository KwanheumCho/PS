#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map_[51][51];
bool chk_[14] = {false,};
vector<pair<int, int> > chicken;
int answer = 1000000; // > 50*50*100

int dist( pair<int,int> A , pair<int,int> B){
    return abs(A.first-B.first) + abs(A.second-B.second);
}

void func_(int start , int cnt, vector<pair<int, int> > tmp){
    if(cnt == M){    
        int tmp_answer = 0;
        for(int r=1; r<=N; r++){
            for(int c=1; c<=N; c++){
                if(map_[r][c] == 1){
                    int min_val = 100;
                    for(int j=0; j<tmp.size(); j++){
                        min_val = min( min_val, dist({r,c} , tmp[j]));
                    }
                    tmp_answer+=min_val;
                    //cout <<" : " <<tmp_answer << endl;
                }
            }
        }
        answer = min(tmp_answer, answer);
        return;
    }

    for(int i=start; i<chicken.size(); i++){
        tmp.push_back(chicken[i]);
        func_(i+1, cnt+1 , tmp);
        tmp.pop_back();
    }
    return;
}

int main(void){
    
    cin >> N >> M;
   
    for(int i=1; i<=N; i++){
        for(int j =1; j<=N; j++){
            cin >> map_[i][j];
            if(map_[i][j]==2) chicken.push_back({i,j}); // i : row,  j:col // 1부터시작
        }
    }
    vector<pair<int, int> > tmp;
    func_(0, 0, tmp);
    cout << answer << endl;


    return 0;
}

