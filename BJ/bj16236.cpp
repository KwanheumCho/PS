#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int mapp[40][40] = {0, };
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

struct pos{
    int r, c;
};
bool chk[40][40] = {false, };
pair<pos, int> find_fish(pos start , int shark_size){
    queue< pair<pos, int> > q;
    chk[start.r][start.c] = true;
    q.push( {start, 0});
    pair<pos, int> X = { {-1, -1}, -1};
    //cout << "here: " << endl;
    while(!q.empty()){
        int row = q.front().first.r;
        int col = q.front().first.c;
        int dist = q.front().second;
        
        if(mapp[row][col] >=1 && mapp[row][col] < shark_size){//먹을수있다!
            X =  { {row, col}, dist };
            while(!q.empty()){
                row = q.front().first.r;
                col = q.front().first.c;
                dist = q.front().second;
                q.pop();
                if(mapp[row][col] >=1 && mapp[row][col] < shark_size && dist == X.second){
                    if( X.first.r > row) X = { {row, col}, dist };
                    else if(X.first.r == row){
                        if(X.first.c > col) X = { {row, col}, dist };
                    } 
                }
            }
            return X;
        }
        q.pop();
        for(int i=0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n){//map 안에 존재해야함
                if(chk[nr][nc]==false && mapp[nr][nc] <= shark_size){
                    q.push({{nr, nc}, dist+1});
                    chk[nr][nc] = true;
                }
            }
        }
    }
    return {{-1, -1},-1 };
}

int func_(pos start, int shark_size, int cnt, int time){
    pair<pos, int >A = find_fish(start, shark_size);
    if(A.second == -1){//먹을생선X
        return time;
    }
    else{
        pos next_start = A.first;
        int dist = A.second;
        //mapp[start.r][start.c] = 0;
        mapp[next_start.r][next_start.c] = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                chk[i][j] = false;
            }
        }
        cnt++;
        if(cnt == shark_size){
            shark_size++;
            cnt = 0;
        } 
        time += dist;
        //cout <<"R: "<< next_start.r <<"C: " << next_start.c <<" size: "<< shark_size<< " time: " << time << endl;
        return func_(next_start, shark_size, cnt, time );
    }
}



int main(void){
    cin >> n;
    pos S;
    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                chk[i][j] = false;
                mapp[i][j] = 0;
            }
        }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            
            if(x==9){
                S.r = i;
                S.c = j; // S = start pos
                mapp[i][j] = 0;
            }
            else mapp[i][j] = x;
        }
    }
    
    int answer = func_(S, 2, 0, 0); 
    //pair<pos, int> A = find_fish(S, 2);
    //cout << A.first.r << " "<< A.first.c << " " << A.second;
    cout << answer << endl;

    return 0;
}