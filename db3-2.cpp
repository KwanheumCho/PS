#include <iostream>
using namespace std;

int main(void){
    int N, M, K;
    cin >> N >> M >> K;
    int* arr = new int [N+1];
    int a =0;
    int b =0;
    for(int i=0; i<N; i++){
        int input;
        cin >> input;
        if(input > a){
            b= a;
            a= input;
        }
        else if(input > b){
            b = input;
        }
    }
    int answer = 0;
    /*
    int k =0;
    for(int i=0; i<M; i++){
        if(k>=K){
            answer += b;
            k = 0;
        }
        else{
            answer += a;
            k++;
        }
    }*/
    answer += M/(K+1) * ((K)*a + b);
    answer += M%(K+1) * (a);
    cout << answer << endl;
}