#include <iostream>
#include <string>
using namespace std;

int main(void){
    string x;
    cin >> x;
    int row, col;
    col = int(x[0]-'a'); // base col = 0;
    row = int(x[1]-'1'); // base row = 0;

    int dx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
    int dy[8] = {-1, 1, 2, 2, -1, 1, -2, -2};
    //row , col <=7
    int answer = 0;
    for(int i=0; i<8; i++){
        int nr = row+dy[i];
        int nc = col+dx[i];
        if(nr>=0 && nr<=7 && nc>=0 && nc<=7){
            answer ++;
        }
    }
    cout << answer << endl;
    return 0;
}