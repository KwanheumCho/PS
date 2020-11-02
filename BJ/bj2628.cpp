#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 100

struct pos{
    int w_chk=0;
    int h_chk=0;
};
pos arr[MAX_SIZE+1][MAX_SIZE+1];
int main(void){
    //cout << arr[5][5];
    
    int w, h;
    cin >> w >> h;
    for(int k=0;k<=w;k++){
        arr[0][k].w_chk = 1;
        arr[h][k].w_chk = 1;
    }
    for(int k=0; k<=h; k++){
        arr[k][0].h_chk = 1;
        arr[k][w].h_chk = 1;
    }

    int cut;
    cin >> cut;
    for(int i=0; i<cut; i++){
        int dir, pos;
        cin >> dir >> pos;
        if(dir == 0){
            for(int k=0; k<=w; k++){
                arr[pos][k].w_chk = 1;
            }
        }
        else{
            for(int k=0; k<=h; k++){
                arr[k][pos].h_chk = 1;
            }
        }
    }
    int first, second;
    vector<int> width;
    vector<int> height;
    
        first = 0;
        for(int i=0; i<=w; i++){
            if(arr[0][i].w_chk ==1 && arr[0][i].h_chk ==1) second = i;
            width.push_back(second-first);
            first = second;
        }
        for(int i=0; i<=h; i++){
            if(arr[i][0].w_chk ==1 && arr[i][0].h_chk ==1) second = i;
            height.push_back(second-first);
            first = second;
        }
        int result = 0;
        for(int i=0; i<height.size(); i++){
            for(int j=0; j<width.size(); j++){
                int tmp = width[j] * height[i];
                if( result < tmp) result = tmp;
            }
        }
    cout << result << endl;
    return 0;
}