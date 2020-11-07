#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int N, M, K;

string answer = "";
int dp[101][101] = {0,};


int case_number(int a, int z){
    if(a==0 || z==0){
        return dp[a][z] = 1;
    }
    if (dp[a][z] != 0) return dp[a][z];
    dp[a][z] = min(case_number(a-1, z) + case_number(a, z-1), MAX+1);
    return dp[a][z];
}


void find_k(int a, int z, int cnt){
    //int total = a+z;
    //cout << "A: "<< a <<"B: "<< z<<" "<<answer<<endl;
    //cout <<"K:"<< K <<"cmp: "<< cnt+case_number(a-1,z) << endl;
    
    if( case_number(a-1, z) == MAX+1 || K < cnt + case_number(a-1,z)){
        answer += "a";
        find_k(a-1, z, cnt);
    }
    else if(K == cnt + case_number(a-1,z)){
        answer += "a";
        if(a-1==0 || z==0){
            if(a-1==0){
                for(int i=0; i<z; i++) answer+='z';
            }
            else{
                for(int i=0; i<a-1; i++) answer += 'a';
            }
        }
        else
        {
            find_k(a-1, z, cnt);
        }
        return;
    }
    else{
        answer += "z";
        find_k(a, z-1, cnt+case_number(a-1,z));
    }
    //cout << answer << endl;
}

int main(void){
    cin >> N >> M >> K; // N개의 "a"와 M개의 "z"
    //경우의수 : (N+M)! / N!M!
    
    
    
    if(case_number(N,M) < K){
        cout << -1 << endl;
    }
    else {
        find_k(N, M, 0);
        cout << answer << endl;
    }
    return 0;
}