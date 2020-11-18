#include <iostream>
#include <string>
using namespace std;
int N, M;
int main(void){
    cin >> N >> M;
    string S;
    cin >> S;
    //Pn을 우선?
    string P = "";
    for(int i=0; i<2*N+1; i++){
        if(i%2==0) P+='I';
        else P+='O';
    }
    //cout << P << endl;
    int answer = 0;
    int cnt = 0;
    for(int i=0; i<M-1; i++){
        if(S[i]=='I'){
            cnt++;    
            if(S[i]==S[i+1]){
                // Px => cnt-1
                int tmp = (cnt-1) - N +1;//현재 Px와 Pn의 차이 + 1
                if(tmp>0) answer += tmp;
                cnt=0;
            }
        }
        if(S[i]=='O'){
            if(S[i]==S[i+1]){
                // Px => cnt-1
                int tmp = (cnt-1) - N +1;//현재 Px와 Pn의 차이 + 1
                if(tmp>0) answer += tmp;
                cnt=0;
            }
        }
    }
    
    if(S[M-1]=='I'){
        cnt++;}
            
        // Px => cnt-1
        int tmp = (cnt-1) - N +1;//현재 Px와 Pn의 차이 + 1
        if(tmp>0) answer += tmp;
        
    cout << answer << endl;
}