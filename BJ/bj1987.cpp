#include <iostream>
#include <string>
#include <vector>
using namespace std;
int R, C;
char map_[21][21];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
bool chk[26] = {false,};
int result = 0;

void func_(int r, int c, int cnt){
    if(cnt > result){
        result = cnt;
    }
    for(int i=0; i<4; i++){
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(nr>=1 && nr<=R && nc>=1 && nc<=C){
           int index = map_[nr][nc]-'A';
           //cout <<"index: "<<index <<endl;
           if(chk[index]==false){
               chk[index] = true;
               func_(nr, nc, cnt+1);
               chk[index] = false;
           } 
        }
    }
    return;
}

int main(void){
    cin >> R >> C;
    // row : R , col: c;
    for(int i=1; i<=R; i++){
        string x;
        cin >> x;
        for(int j=0; j<C; j++){
            map_[i][j+1] = x[j];
        }
    }//for
    chk[map_[1][1]-'A'] = true;
    func_(1, 1, 1);
    cout << result << endl;
}