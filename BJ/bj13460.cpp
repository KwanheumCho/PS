#include <iostream>
#include <vector>
using namespace std;

int N, M;
struct pos{
    int h, w;
};

void move(vector<char> board[], pos Red, pos Blue, int dir){
    int dh[4] = {-1 ,1, 0, 0};
    int dw[4] = {0, 0, -1, 1};
    pos new_Red, new_Blue;
    bool red =true, blue = true;
    new_Red.h = Red.h + dh[dir];
    new_Red.w = Red.w + dw[dir];
    new_Blue.h = Blue.h + dh[dir];
    new_Blue.w = Blue.w + dw[dir];
    while(red || true){
        red = true;
        blue = true;
        if(board[new_Red.h][new_Red.w] !='.') red=false;
        else{
            while(board[new_Red.h][new_Red.w] == '.'){
                board[Red.h][Red.w] = '.';
                Red = { new_Red.h, new_Red.w};
                board[Red.h][Red.w] = 'R';
                new_Red.h += dh[dir];
                new_Red.w += dw[dir];
            }
        }
    }
}


int main(void){
    cin >> N >> M;
    vector<char> * board = new vector<char> [N];
    char tmp;
    pos Red, Blue;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> tmp;
            board[i].push_back(tmp);
            if(tmp == 'R'){
                Red.h = i;
                Red.w = j;
            }
            if(tmp == 'B'){
                Blue.h = i;
                Blue.w = j;
            }
        }
    }
    solve()


    return 0;
}