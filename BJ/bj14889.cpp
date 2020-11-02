#include <iostream>
#include <vector>
using namespace std;
int N;
int S[20][20];
bool check[20] = {false,};
int result = 1000000;
vector<int> A;
vector<int> B;  
void divide(int number, int cnt){
    if(cnt == N/2){
        //최소값 구하기
        for(int i=0; i<N; i++){
            if(check[i]) A.push_back(i);
            else B.push_back(i);
        }
        int tmp_A=0;
        int tmp_B=0;
        for(int i=0; i<N/2; i++){
            for(int j=i+1; j<N/2; j++){
                tmp_A+= S[A[i]][A[j]] + S[A[j]][A[i]];
                tmp_B+= S[B[i]][B[j]] + S[B[j]][B[i]];
            }
        }
        int x = abs(tmp_A-tmp_B);
        //cout << x << endl;
        if(result>x) result = x;
        A.clear();
        B.clear();
        return;
    }
    else if(cnt > N/2) return;
    
    for(int i=number; i<N; i++){
        if(check[number] == false){
            check[number] = true;
            divide(i+1, cnt+1);
            check[number] = false;
        }
    }
}


int main(void){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> S[i][j];
        }
    }
    divide(0,0);
    cout << result << endl;
    return 0;
}