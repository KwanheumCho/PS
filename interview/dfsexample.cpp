#include <iostream>
using namespace std;

int row, col;
bool arr[3][3];
int result = 0;

void print_arr() {
    for(int i=0; i< row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j]<< " ";
        }
        cout << endl;
    }
    cout << endl;
}

void check(int c_row, int c_col, int count){
    if(count == 3){
        //형태출력
        print_arr();
        result ++;
    }
    else{
        if(c_row == row){
            return;
        }
        else{
            arr[c_row][c_col] = true;
            if(c_col +1 == col) check(c_row+1, 0, count+1);
            else check(c_row, c_col+1, count+1);
            
            arr[c_row][c_col] = false;
            if(c_col +1 == col) check(c_row+1, 0, count);
            else check(c_row, c_col+1, count);
        }
    }
}

int main(void){
    row = 3; col = 3;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr[i][j] = false;
        }
    }
    check(0,0,0);

    cout << "final result: " << result << endl;
    return 0;
}