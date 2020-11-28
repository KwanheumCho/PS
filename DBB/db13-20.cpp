#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

char map_[7][7];
int N;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
bool flag = false;
void func_(int cnt){
    if(cnt == 3){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map_[i][j] == 'T'){
                    //bool detected = false;
                    for(int dir=0; dir<4; dir++){// 4방향
                        int row = i;
                        int col = j;
                        while(true){
                            int nr = row+dr[dir];
                            int nc = col+dc[dir];
                            if(nr<0 || nr>=N || nc<0 || nc>=N || map_[nr][nc]=='O'){
                                break;
                            }
                            else if(map_[nr][nc]=='S') return;
                            row = nr;
                            col = nc;    
                        }
                    }
                }
            }
        }
        flag = true;
        return;    
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map_[i][j] == 'X'){
                map_[i][j] = 'O';
                func_(cnt+1);
                map_[i][j] = 'X';
            }
        }
    }

}


int main(void){
    
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map_[i][j];
        }
    }
    func_(0);
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}