#include <iostream>
#include <queue>
using namespace std;

int K, W, H;
int map_[200][200];
int result = 200*200;


int dx[12] = {-2, -1, 1, 2, 2, 1, -1, -2, -1, 0, 1, 0};
int dy[12] = {-1, -2, -2, -1, 1, 2, 2, 1, 0, -1, 0, 1};
queue< pair< pair<int , int > , pair<int, int> > > q; // y좌표 x좌표 k값 cnt값
bool chk_[200][200][31] = {false,};

void move_func(int x, int y, int k, int cnt){
    q.push( make_pair( make_pair(x, y) , make_pair(k, cnt) )  );
    chk_[x][y][k] = true;
    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        k = q.front().second.first;
        cnt = q.front().second.second;
        //cout << "x: "<< x<< "y: "<<y<<" s: "<<q.size() << endl;
        q.pop();
        if(x == W-1 && y == H-1){
            if(cnt < result) result = cnt;
            return;
        }
        for(int i=0; i<12; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < W && ny >=0 && ny < H){
                if(map_[ny][nx] == 0){
                    if(i<8 && k < K && !chk_[ny][nx][k+1]){
                        //q push
                        chk_[ny][nx][k+1] = true;
                        q.push( make_pair( make_pair(nx, ny) , make_pair(k+1, cnt+1) )  );
                    }
                    else if(i>=8 && !chk_[ny][nx][k]){
                        //q push
                        chk_[ny][nx][k] = true;
                        q.push( make_pair( make_pair(nx, ny) , make_pair(k, cnt+1) )  );
                    }
                }
            }
        }//for
    }//while
    return;

}


int main(void){
    
    cin >> K; // K번 움직일 수 있다
    cin >> W >> H; // 가로길이 W , 세로길이 H [h][w]
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> map_[i][j];
        }
    }
    //시작점 : 맨왼쪽위 (0,0)
    //도착점 : 맨오른쪽아래 (H-1,W-1)
    move_func(0, 0, 0, 0);
    if(result!= 200*200) cout << result << endl;
    else cout << -1 << endl;
    return 0;
}