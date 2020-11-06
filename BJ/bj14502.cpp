#include <iostream>

using namespace std;

int map_[8][8] = {0,};
struct node{
    int x;
    int y;
};
node vir_[10];
int vir_number=0;
int N, M;

int virus_able = 64;

int spread(node v){
    int x = v.x;
    int y = v.y;
    int result = 0;
    //동서남북
    if(y+1< M && map_[x][y+1] == 0){
        map_[x][y+1] = 2;
        result += 1 + spread({x, y+1});
    }
    if(y-1>=0 && map_[x][y-1] == 0){
        map_[x][y-1] = 2;
        result += 1 + spread({x, y-1});
    }
    if(x+1< N && map_[x+1][y] == 0){

        map_[x+1][y] = 2;
        result += 1 + spread({x+1, y});
    }
    if(x-1 >=0 && map_[x-1][y] == 0){
        map_[x-1][y] = 2;
        result += 1 + spread({x-1, y});
    }
    return result;
}

int virus(){
    int result = 0;
    for(int i=0; i<vir_number; i++){
        result += spread(vir_[i]);
    }
    return result;
}

void func(int cnt){
    if(cnt ==3){
        int tmp_map[8][8];
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                tmp_map[i][j] = map_[i][j];
            }
        }
        int tmp = virus();
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                map_[i][j] = tmp_map[i][j];
            }
        }
        if(tmp < virus_able){
            virus_able = tmp;
        }
        
       return;
    }
    //3칸을 막는 함수
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map_[i][j] == 0){
                map_[i][j] = 1;
                func(cnt+1);
                map_[i][j] = 0;
            }
        }
    }
}


int main(void){
    int empty = 0;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int x;
            cin >> x;
            map_[i][j] = x;
            if(x==2){
                vir_[vir_number++] = {i, j};
            }
            if(x==0){
                empty++;
            }  
        }
    }
    func(0);
    //cout << virus_able << endl;
    cout << empty-virus_able-3 << endl;
    return 0;
}