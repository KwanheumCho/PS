#include <iostream>

using namespace std;

int K, W, H;
int map_[201][201];
int dp_[201][201];
int result = 200*200;



int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int ddx[4] = {-1, 0, 1, 0};
int ddy[4] = {0, -1, 0, 1};

void mongkey_move(int y, int x, int cnt){
    //cout << "mon : " << y <<" "<< x << endl;
    if( y == H-1 && x == W-1){
        if(cnt < result){
            result = cnt;
        }
        return;
    }
    if(cnt > result) return;

    for(int i=0; i<4; i++){
        int nx = x + ddx[i];
        int ny = y + ddy[i];
        if( nx>=0 && nx<W && ny>=0 && ny<H){
            if(map_[ny][nx]==0) mongkey_move(ny,nx, cnt+1);
        }
    }
}

void horse_move(int y, int x, int cnt){
    if(cnt <= K){
        //한칸씩 이동
        mongkey_move(y , x, cnt);
        //cout << "hor : " << y <<" "<< x << endl;
        
    }
    if(cnt == K) return;
    for(int i=0; i<8; i++){
        //말의 움직임처럼 이동
        int nx = x+dx[i];
        int ny = y+dy[i];
        if( nx>=0 && nx<W && ny>=0 && ny<H){
            if(map_[ny][nx]==0) {
                horse_move(ny, nx, cnt+1);
            }
        }
    }
}
/*
int dx[12] = {-2, -1, 1, 2, 2, 1, -1, -2, -1, 0, 1, 0};
int dy[12] = {-1, -2, -2, -1, 1, 2, 2, 1, 0, -1, 0, 1};

void move_func(int y, int x, int k, int cnt){
    if(cnt > result) return;
    if( y == H-1 && x == W-1){
        if(cnt < result){
            result = cnt;
        }
        return;
    }

    for(int i=0; i<12; i++){
        //말의 움직임처럼 이동
        int nx = x+dx[i];
        int ny = y+dy[i];
        if( nx>=0 && nx<W && ny>=0 && ny<H){
            if(map_[ny][nx]==0) {
                if(i<8 && k<K) move_func(ny, nx, k+1, cnt+1);
                if(i>=8) move_func(ny, nx, k, cnt+1);
            }
        }
    }
}
*/

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> K; // K번 움직일 수 있다
    cin >> W >> H; // 가로길이 W , 세로길이 H [h][w]
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> map_[i][j];
        }
    }
    //시작점 : 맨왼쪽위 (0,0)
    //도착점 : 맨오른쪽아래 (H-1,W-1)
    
    horse_move(0 , 0, 0);
    if(result == 200*200){
        cout << result << endl;
    } 
    else cout << result << endl;
    
    /*
    move_func(0, 0, 0, 0);
    if(result == 200*200) cout << -1 << endl;
    else cout << result << '\n';
    */
    return 0;
}