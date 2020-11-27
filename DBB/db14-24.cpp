#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<int> v;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int answer = 0;
    int size = v.size();
    if(size%2 == 1){
        answer = v[size/2];
    }
    else{
        int tmp1 = 0;
        int tmp2 = 0;
        
        for(int j=0; j<v.size(); j++){
            tmp1 += abs(v[j] - v[size/2-1]);
        }
        for(int j=0; j<v.size(); j++){
            tmp2 += abs(v[j] - v[size/2]);
        }
        //cout << tmp1 << " " << tmp2 << endl;
        if(tmp1 > tmp2) answer = v[size/2];
        else answer = v[size/2-1];
        
    }
    /*
    //사실 중간값이 두개 나오는 경우에도 중간값 좌 우로 값이 동일하게 분포, 따라서 tmp1과 tmp2는 항상 같을 수 밖에...
    //따라서 간단하게 중간값 중에 작은걸 출력해도 정답.
    cout << v[(n - 1) / 2] << '\n';
    */
    cout << answer << endl;
    return 0;
}