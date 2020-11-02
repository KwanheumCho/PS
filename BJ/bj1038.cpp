#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> result;
void make_desc(long long before, int cnt){
    result.push_back(before);
    if(cnt>=10) return;
    for(int i=0; i<10; i++){
        if( i < before%10){

            make_desc(before*10 +i , cnt+1);
        }
    }
}

int main(void){
    int N;
    cin >> N; //X>=0
    for(long long i=0; i<10; i++){
        make_desc(i, 1); // 9876543210
    }
    sort(result.begin(), result.end());
    if(N>=result.size()) cout << -1 << endl;
    else cout << result[N] << endl;
    //cout <<" chk" << desc_chk(10);
}