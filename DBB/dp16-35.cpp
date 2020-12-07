#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//답지 참고
int main(void){
    int n;
    int ugly[1000];
    cin >> n;

    int i2= 0, i3=0, i5=0;
    int next2=2, next3=3, next5=5;

    ugly[0]=1;
    for(int l=1; l<n; l++){
        ugly[l] = min(next2, min(next3, next5));
        if(ugly[l]==next2){
            i2+=1;
            next2=ugly[i2]*2;
        }
        if(ugly[l]==next3){
            i3+=1;
            next3=ugly[i3]*3;
        }
        if(ugly[l]==next5){
            i5+=1;
            next5=ugly[i5]*3;
        }
    }

    cout << ugly[n-1] << endl;
}