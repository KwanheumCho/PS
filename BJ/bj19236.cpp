#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n = 4;
struct pos{int num, dir;};

int dr[9] = {-1000, -1, -1, 0, 1, 1, 1, 0, -1};
int dc[9] = {-1000, 0, -1, -1, -1, 0, 1, 1, 1};
int result = 0;

void fish_move(pos (*mapp)[5], pair< pair<int, int> , int >* now){
    for(int i=1; i<=16; i++){
        pair<int, int> now_fish = now[i].first; // 현재 생선의 위치
        if(now_fish.first== -1) continue; // 잡아먹혀서 없음
        int dir = now[i].second;
        for(int j=0; j<8; j++){
            int next_dir;
            //방향 설정
            if(dir+j >8) next_dir = (dir+j)%9 +1;
            else next_dir = dir+j;
            //
            int nr = now_fish.first + dr[next_dir];
            int nc = now_fish.second + dc[next_dir];
            if(nr>=0 && nr<4 && nc>=0 && nc<4){//범위 안
                if(mapp[nr][nc].num != -1){//상어가아니다
                    int next = mapp[nr][nc].num;
                    //현재 물고기 : i, 위치 : now_fish;
                    //이동방향 물고기 : next
                    mapp[nr][nc].num = i;
                    now[i].first = {nr, nc};
                    now[i].second = next_dir;
                    mapp[nr][nc].dir = next_dir;
                    if(next!=0){
                        mapp[now_fish.first][now_fish.second].num = next;
                        now[next].first = now_fish;
                        mapp[now_fish.first][now_fish.second].dir = now[next].second;
                    }
                    else{
                        mapp[now_fish.first][now_fish.second] = {0,0};
                    }
                    break;
                }
            }
        }//for 8
    }//for 16
}

void func_(pair<int,int> S, int cnt, pos(*mapp)[5], pair< pair<int, int> , int >* now ){
    //상어는 0,0에서 시작
    pos t_mapp[5][5];
    pair< pair<int, int> , int > t_now[17];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            t_mapp[i][j] = mapp[i][j];
        }
    }
    for(int i=0; i<=16; i++){
        t_now[i] = now[i];
    }
    //
    int feed_fish = t_mapp[S.first][S.second].num;
    cnt += feed_fish; 
    t_mapp[S.first][S.second].num = -1; // -1이 상어를 의미
    t_now[feed_fish] = {{-1,-1},-1}; // 잡아먹힌 생선의 표현
    int dir = t_mapp[S.first][S.second].dir;
    result = max( result, cnt);

    fish_move( t_mapp, t_now);


    for(int i=1; i<4; i++){
        int nr = S.first + dr[dir] * i;
        int nc = S.second + dc[dir] * i;
        t_mapp[S.first][S.second]= {0, 0};
        if(nr>=0 && nr<n && nc>=0 && nc<n){
            if(t_mapp[nr][nc].num>=1 && t_mapp[nr][nc].num<=16){   
                func_({nr, nc}, cnt , t_mapp, t_now);
            }
        }
    }
    return;
}

int main(void){
    pos mapp[5][5]; // 좌표상에서의 num, dir
    pair< pair<int, int> , int > now[17]; // 물고기번호에 따른 좌표와 방향
    for(int i=0; i<17; i++) now[i] = {{-1, -1},-1};
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int x, y;
            cin >> x >> y;
            mapp[i][j] = {x , y};
            now[x] = {{i,j}, y};
        }
    }
    
    func_({0,0 }, 0, mapp, now);
    cout << result << endl;

}