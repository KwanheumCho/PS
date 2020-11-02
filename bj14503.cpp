#include <iostream>
using namespace std;

int N, M;
int map[50][50]; // map
bool clean[50][50] = {false,};
struct pos{int x, y;};
int result = 0;

void start_clean(pos& robot_pos, int dir){
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, +1, 0};
    int left_dir[4] = {3, 0, 1, 2};
    // 1. 현재위치 청소
    clean[robot_pos.y][robot_pos.x] = true;
    result++;
    //cout<<result<<" "<<robot_pos.x<<" " << robot_pos.y<< " " << dir<<endl;
    int cnt = 0;
    while(true){
        // 2. 왼쪽방향 탐색
        int tmp_dir = left_dir[dir];
        pos next_pos = {robot_pos.x+dx[tmp_dir], robot_pos.y+dy[tmp_dir]};
        cnt++;
        if( map[next_pos.y][next_pos.x] != 1 && clean[next_pos.y][next_pos.x] == false){
            //청소할 공간 존재
            start_clean(next_pos , tmp_dir);
            break;
        }
        else if( map[next_pos.y][next_pos.x] == 1 || clean[next_pos.y][next_pos.x] == true){
            //청소할 공간 X
            dir = tmp_dir;
            if(cnt ==4){
                if(map[robot_pos.y-dy[dir]][robot_pos.x-dx[dir]] == 1){
                    break; //작동멈춤
                }
                else{
                    robot_pos = {robot_pos.x-dx[dir],robot_pos.y-dy[dir]};
                }
                cnt = 0;
            }
            continue;
        }
    }//while
}

int main(void){
    cin >> N >> M;
    pos robot_pos;
    cin >> robot_pos.y >> robot_pos.x;
    int dir;
    cin >> dir;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    start_clean(robot_pos, dir);
    cout << result << endl;

    return 0;
}