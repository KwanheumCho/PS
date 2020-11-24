    #include <iostream>

    using namespace std;
    int map_[101][101];

    int dir_func(int dir, char input){
        if(input=='D'){
            dir+=1;
            if(dir==4) dir=0;
        }
        else if(input=='L'){
            dir-=1;
            if(dir==-1) dir=3;
        }
        return dir;
    }

    int main(void){
        int N, K;
        cin >> N >> K;
        // 사과의 위치
        for(int i=0; i<K; i++){
            int row, col;
            cin >> row >> col;
            map_[row][col] = 1; // 1 means apple!
        }
        int L;
        cin >> L;
        int now = 0;
        int dir = 0; //오른쪽이 0
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        bool chk_[101][101]={false ,} ;
        int tail_dir[101][101];
        int x =1, y=1;
        int tail_x= 1, tail_y=1;
        chk_[y][x] = true;
        tail_dir[tail_y][tail_x] = dir;

        bool end_flag = false;
        for(int i=0; i<L; i++){
            int change_time;
            char next_dir;
            cin >> change_time >> next_dir;
            while(now < change_time){
                //우선 현재 방향대로 1칸만큼 진행
                int nx = x+dx[dir];
                int ny = y+dy[dir];
                //cout << "nx: "<< nx<< " ny: "<< ny << "now: "<<now<<endl;
                if(nx<1 || nx>N || ny<1 || ny>N || chk_[ny][nx]==true){//벽에충돌
                    now++;
                    end_flag = true;
                    break;
                }
                else{
                    chk_[ny][nx] = true;
                    tail_dir[y][x] = dir;
                    x = nx;
                    y = ny;
                    if(map_[ny][nx]!=1){//꼬리를 false로 처리
                        chk_[tail_y][tail_x] = false;
                        int tmpx = tail_x;
                        int tmpy = tail_y;
                        tail_x += dx[tail_dir[tmpy][tmpx]];
                        tail_y += dy[tail_dir[tmpy][tmpx]];
                    }
                    else map_[ny][nx] = 0;
                }
                now++;
            }//while
            if(end_flag) break;
            dir = dir_func(dir, next_dir);
        }
        while(!end_flag){
            int nx = x+dx[dir];
                int ny = y+dy[dir];
                if(nx<1 || nx>N || ny<1 || ny>N || chk_[ny][nx]==true){//벽에충돌
                    now++;
                    end_flag = true;
                    break;
                }
                else{
                    chk_[ny][nx] = true;
                    tail_dir[y][x] = dir;
                    x = nx;
                    y = ny;
                    if(map_[ny][nx]!=1){//꼬리를 false로 처리
                        chk_[tail_y][tail_x] = false;
                        int tmpx = tail_x;
                        int tmpy = tail_y;
                        tail_x += dx[tail_dir[tmpy][tmpx]];
                        tail_y += dy[tail_dir[tmpy][tmpx]];
                    }
                    else map_[ny][nx] = 0;
                }
                now++;
        }

        cout << now << endl;
    }