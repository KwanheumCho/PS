#include <iostream>

using namespace std;
int board[101][101];
//char dir[]
int main(void){
    int N;
    cin >> N; // board size
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            board[i][j] = -1; // -1 means nothing exist cur pos;
        }
    }
    int K;
    cin >> K;
    for(int i=0; i<K; i++){
        int row, col;
        cin >> row >> col;
        board[row][col] = 4; // 4 means apple exist;
    }
    int dir_number;
    cin >> dir_number;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int cur_dir = 0;
    int cur_x = 1; int cur_y = 1; 
    int bx = 1; int by = 1;
    int nx, ny;
    int result = 0;
    bool flag = false;
    board[cur_y][cur_x] = 0; 
    for(int j=0; j<dir_number; j++){
        int time;
        char x;
        cin >> time >> x;
        while(true){
            nx = cur_x + dx[cur_dir];
            ny = cur_y + dy[cur_dir];
            if((nx > N|| nx < 1) || (ny > N || ny < 1) || (board[ny][nx] >= 0 && board[ny][nx]<=3)) {
                flag = true; // means end game
                result += 1;
                break;
            }
            else{
                if(board[ny][nx] == 4){
                    board[ny][nx] = cur_dir;
                    cur_x = nx;
                    cur_y = ny;
                }
                else{
                    board[ny][nx] = cur_dir;
                    cur_x = nx;
                    cur_y = ny;
                    int tmp = board[by][bx]; // we have to load snake's tail pos.
                    board[by][bx] = -1;
                    bx += dx[tmp];
                    by += dy[tmp];
                }
            }
            result += 1;
            if(time == result){
                if(x == 'D') cur_dir = (cur_dir+1)%4;
                else cur_dir = (cur_dir+3)%4;
                board[cur_y][cur_x] = cur_dir; // if direction change, then also change snake's cur board information.
                break;
            }
            
        }
        if(flag) break;
    }
    if(flag) cout << result << endl;
    else{
         while(true){
            
            nx = cur_x + dx[cur_dir];
            ny = cur_y + dy[cur_dir];
            if((nx > N|| nx < 1) || (ny > N || ny <1) || (board[ny][nx] >= 0 && board[ny][nx]<=3)) {
                flag = true; // means end game
                result += 1;
                break;
            }
            else{
                if(board[ny][nx] == 4){
                    board[ny][nx] = cur_dir;
                    cur_x = nx;
                    cur_y = ny;
                }
                else{
                    board[ny][nx] = cur_dir;
                    cur_x = nx;
                    cur_y = ny;
                    int tmp = board[by][bx];
                    board[by][bx] = -1;
                    bx += dx[tmp];
                    by += dy[tmp];
                }
            }
            result += 1;   
        }
        cout << result << endl;
    }

    return 0;
}