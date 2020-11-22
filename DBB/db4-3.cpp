#include <iostream>

using namespace std;

int map_[51][51];
bool chk_[51][51] = {false,};
int main(void){
    //input
    int N, M;
    cin >> N >> M;
    int x, y, dir;
    cin >> x >> y>> dir;
    //지도
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map_[i][j];
        }
    }
    
    chk_[y][x] = true; 
    int answer = 1;
    int dy[4] = {-1 ,0, 1, 0}; //북 동 남 서
    int dx[4] = {0, 1, 0, -1};
    int n_dir = 0;
    int cnt = 0;
    int nx;
    int ny;
    while(true){
        //cout << cnt << endl;
        //다음 방향//왼쪽으로 90도
        if(cnt == 4){//방향을 모드 체크한 경우, 한칸 뒤로 가야돼
            nx = x -dx[dir];
            ny = y -dy[dir];
            
            if((nx<0 || nx>=M || ny<0 || ny>=N)||(map_[ny][nx]==1)){
                break;
            }
            else{//이미 방문한 지점이어야함. cnt가 4.
                x = nx;
                y = ny;
                cnt = 0;
            }
        }
        else{
            if(dir==0) n_dir = 3;
            else n_dir -= 1;
            nx = x+dx[n_dir];
            ny = y+dy[n_dir];
            if(nx>=0 && nx<M && ny>=0 && ny<N){ //다음 좌표가 타당한가.
                if(chk_[ny][nx]==false && map_[ny][nx]==0){ //갈수있는가?
                    x = nx; y= ny; //다음칸으로 전진
                    chk_[y][x] = true;
                    answer++;
                    cnt = 0;
                }
                else{
                    //방향만전환. if문이랑 같이수행.
                    cnt ++;
                }
                dir = n_dir;
            }
            else{
                //외곽은 바다이다.
                cnt ++;
                dir = n_dir;
            }
        }
    }
    cout << answer << endl;
    return 0;
}