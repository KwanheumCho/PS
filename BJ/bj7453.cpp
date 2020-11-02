#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 4000

//long long arr[MAX_SIZE][4];
int arr[MAX_SIZE][4];

//map<int, int> m;
//map의 오버헤드가 큰 경우 시간초과,,
int main(void){
    int number;
    cin >> number;
    for(int i=0; i<number; i++){
        cin >> arr[i][0] >> arr[i][1]>>arr[i][2]>>arr[i][3];
    }
    int tmp;
    vector<int> X;
    for(int i=0; i<number; i++){
        for(int j=0; j<number; j++){
            tmp = arr[i][0] + arr[j][1];
            X.push_back(tmp);
        }
    }   
    sort(X.begin(), X.end());
    long long result = 0;
    for(int i=0; i<number; i++){
        for(int j=0; j<number; j++){
            tmp = arr[i][2] + arr[j][3];
            int lb = lower_bound(X.begin(), X.end(), -tmp) - X.begin();
            int ub = upper_bound(X.begin(), X.end(), -tmp) - X.begin();
            if(-tmp == X[lb]) result+=(ub-lb);
        }
    }
    cout << result << endl;


    return 0;
}