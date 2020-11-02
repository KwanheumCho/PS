#include <iostream>

using namespace std;

int main(void){

    int n, l;
    cin >> n >> l;
    int** input = new int*[n];
    int** input2 = new int*[n];
    bool** check = new bool*[n];
    bool** check2 = new bool*[n];
    for(int i=0; i<n; i++){
        input[i] = new int[n];
        input2[i] = new int[n];
        check[i] = new bool[n];
        check2[i] = new bool[n];
    }
    //input
    for(int i=0; i<n; i++){
        for(int ii=0; ii<n; ii++){
            cin >> input[i][ii];
            check[i][ii] = 0;
            input2[ii][i] = input[i][ii];
        }
    }

    
    // height <= 10;
    int result=0;
    int left , right, gap;
    for(int i=0; i<n; i++){
        int counter = l;
        int flag = 1;
        int cflag = 1;
        for(int ii=0; ii<n-1; ii++){
            left = input[i][ii];
            right = input[i][ii+1];
            gap = left - right;
            if(gap == 0){
                if(flag==1 ) ;//continue;
                else {  counter--; 
                        check[i][ii+1] = 1;}//경사도를 놨으니 counter--;
            }
            else if(gap >= 2 || gap <= -2) break;
            else if(gap == 1){
                if(flag==1){
                    flag = 0 ; //경사도를 놔야한다는 의미;
                    counter--;
                    check[i][ii+1] = 1;
                }
                else break;
            }
            else if(gap == -1){
                for(int k =0; k<l; k++){
                    if(check[i][ii-k]) cflag = 0; // 경사도가 이미 존재함, 따라서 놓을수없음
                }
                for(int k=0; k<l-1; k++){
                    int tmp = input[i][ii-k] - input[i][ii-k-1];
                    if(tmp !=0) cflag = 0; // 경사도 길이 l 만큼 평평하지않다는 의미
                }
                if(cflag ==0) break; 
            }

            if(counter ==0){
                counter = l;
                flag = 1; // 다시 reset;
            }

            if(ii == n-2 && flag == 1) {
                result++;
                //cout << i << " " << ii << endl;
            }
        }
    }

    //int left , right, gap;
    for(int i=0; i<n; i++){
        int counter = l;
        int flag = 1;
        int cflag = 1;
        for(int ii=0; ii<n-1; ii++){
            left = input2[i][ii];
            right = input2[i][ii+1];
            gap = left - right;
            if(gap == 0){
                if(flag==1 ) ;//continue;
                else {  counter--; 
                        check2[i][ii+1] = 1;}//경사도를 놨으니 counter--;
            }
            else if(gap >= 2 || gap <= -2) break;
            else if(gap == 1){
                if(flag==1){
                    flag = 0 ; //경사도를 놔야한다는 의미;
                    counter--;
                    check2[i][ii+1] = 1;
                }
                else break;
            }
            else if(gap == -1){
                for(int k =0; k<l; k++){
                    if(check2[i][ii-k]) cflag = 0; // 경사도가 이미 존재함, 따라서 놓을수없음
                }
                for(int k=0; k<l-1; k++){
                    int tmp = input2[i][ii-k] - input2[i][ii-k-1];
                    if(tmp !=0) cflag = 0; // 경사도 길이 l 만큼 평평하지않다는 의미
                }
                if(cflag ==0) break;
                //else; //check2 change? 
            }

            if(counter ==0){
                counter = l;
                flag = 1; // 다시 reset;
            }

            if(ii == n-2 && flag == 1) {
                result++;
                //cout << i << " " << ii << endl;
            }
        }
    }

    cout << result << endl;
}