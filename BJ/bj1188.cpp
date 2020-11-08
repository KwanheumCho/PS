#include <iostream>

using namespace std;

int N, M;

int func(int n, int m){
    
    int x;
    while(m!=0){
        x = n%m;
        n = m;
        m = x;
    }
    return n;
}


int main(void){
    cin >> N >> M;
    //소시지가 N개 평론가 M명
    //소시지를 전부 이어붙인 상태에서 , M등분을 하는 경우를 생각. => M-1
    //N과 M의 관계(공약수)에 따라서 이미 컷팅이 되어 있다. => func(N,M)-1

    int answer = M-1-(func(N,M)-1);
    cout << answer << endl;
    return 0;

}