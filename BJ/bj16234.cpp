#include <iostream>
#include <queue>
using namespace std;

int N, L, R;
int pop_[51][51];
bool chk_[51][51][2000] = {false,};
bool flag;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue< pair<int, int> > update;
int func_(int r, int c, int cnt){
    int tmp = 0;
    queue< pair<int, int> > q;
    tmp += pop_[r][c];
    q.push( make_pair(r, c) );
    update.push(make_pair(r, c));
    chk_[r][c][cnt] = true;
    while(!q.empty()){
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r+dy[i];
            int nc = c+dx[i];
            if(nr>=1 && nr<=N && nc>=1 && nc<=N){
                if(chk_[nr][nc][cnt]==false){
                    int gap = abs(pop_[nr][nc] - pop_[r][c]);
                    if(gap>=L && gap<=R){
                        chk_[nr][nc][cnt] = true;
                        q.push( make_pair(nr,nc));
                        update.push(make_pair(nr,nc));
                        tmp += pop_[nr][nc];
                        flag = true;
                    }
                }
            }
        }//for
    }//while
    return tmp;
}


int main(void){
    cin >> N >> L >> R;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> pop_[i][j];
        }
    }
    int k = 0;
    int sum;
    int mean;
    while(true){
        flag = false;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(!chk_[i][j][k]) {
                    sum = func_(i, j, k);
                    mean = sum / update.size();
                    while(!update.empty()){
                        int row = update.front().first;
                        int col = update.front().second;
                        pop_[row][col] = mean;
                        update.pop();
                    }
                }
            }
        }
        if(flag) k++;
        else break;
    }
    cout << k << endl;
    

    return 0;
}