#include <iostream>
#include <string>
using namespace std;
bool number_chk[10] ={false, };
int answer = 0;


bool possible_chk(int x){
    //cout <<"ehel"<<endl;
    string tmp = to_string(x);
    for(int i=0; i<tmp.size(); i++){
        int a = int(tmp[i]-'0');
        if(number_chk[a]) return false; // false means 고장난 버튼이 포함
    }
    return true;
}


int main(void){
    int N, M;
    cin >> N; // N<=500,000
    cin >> M;
    for(int i=0; i<M; i++){
        int wrong;
        cin >> wrong;
        number_chk[wrong] = true;
    } // 고장난 숫자는 number_chk에서 true로 표현
    
    int min = 1000000;
    int counter = 1000000;
    for(int i=0; i<=500000;i++){
        if(possible_chk(N+i)){
            if(min >= i && counter > N+i){
                min = i;
                counter = N+i;
            }
            break;
        }
    }
    for(int j=0; j<=N; j++){
        if(N-j >=0 && possible_chk(N-j)){
            if(min >= j && counter > N-j){
                min = j;
                counter = N-j;
            }
             break;
        }
    }
    string u = to_string(counter);
    answer = min + u.size();
    
    if( abs(N-100) < answer) answer = abs(N-100);
    cout << answer << endl;

}