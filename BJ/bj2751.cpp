#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int main(void){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << '\n';
    }
}

