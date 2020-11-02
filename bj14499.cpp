#include <iostream>
using namespace std;

int N, M;
int arr[20][20];
struct pos{
    int x, y;
};
struct dice{
    int one, two, three, four, five, six;
};
int roll(pos& dice_pos, dice& T, int dir){
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int cur_x = dice_pos.x +dx[dir-1];
    int cur_y = dice_pos.y +dy[dir-1];
    if(cur_x >= M || cur_y >= N || cur_x<0 || cur_y<0){
        return -1;
    }
    else{
        int tmp;
        dice_pos = {cur_x, cur_y};
        if(dir == 4){
            tmp = T.one;
            T.one = T.two;
            T.two = T.six;
            T.six = T.five;
            T.five = tmp;
        }
        else if(dir == 3){
            tmp = T.one;
            T.one = T.five;
            T.five = T.six;
            T.six = T.two;
            T.two = tmp;
        }
        else if(dir == 2){
            tmp = T.one;
            T.one = T.three;
            T.three = T.six;
            T.six = T.four;
            T.four = tmp;
        }
        else if(dir ==1){
            tmp = T.one;
            T.one = T.four;
            T.four = T.six;
            T.six = T.three;
            T.three = tmp;
        }    
    }
    
    if(arr[dice_pos.y][dice_pos.x] ==0){
            arr[dice_pos.y][dice_pos.x]=T.six;
        }
    else{
            T.six = arr[dice_pos.y][dice_pos.x];
            arr[dice_pos.y][dice_pos.x] = 0;
     
     }
    return T.one;
}

int main(void){
    cin >> N >> M;
    pos dice_pos;
    cin >> dice_pos.y >> dice_pos.x;
    
    dice T ={0, 0, 0, 0, 0, 0};

    int k;
    cin >> k;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    int* instruction = new int[k];
    for(int i=0; i<k; i++){
        cin >> instruction[i];
    }
    
    for(int j=0; j<k; j++){
        int result = roll(dice_pos, T, instruction[j]);
        if(result != -1){
            cout << result <<endl;
        }
    }
    
    return 0;
}
