#include <iostream>
#include <string>
using namespace std;

int main(void){
    string x;
    cin >> x;
    int mid = x.size()/2;
    int left = 0;
    int right =0;
    for(int i=0; i<x.size(); i++){
        if(i<mid){
            left += int(x[i]-'0');
        }
        else{
            right += int(x[i]-'0');
        }
    }
    if(left == right) cout <<"LUCKY"<<endl;
    else cout <<"READY" <<endl;
    return 0;
}