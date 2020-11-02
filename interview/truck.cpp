#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int main(void){
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = {7, 4, 5, 6};
     int answer = 0;
    //다리길이 : brideg_length..
    //트럭이 올라가고 length만큼 시간이 지나야 함.
    //다리에 같이 올라갈수있는애는 같이 가야돼
    queue<int> q;
   // sort( truck_weights.begin(), truck_weights.end(), less<int>());
    int q_sum = 0;
    vector<int>::iterator iter; 
    while(!truck_weights.empty()){
        cout << "while: " << endl;
        for(iter=truck_weights.begin(); iter!=truck_weights.end(); iter++){
            cout << * iter << "size: "<< truck_weights.size() <<endl;
            truck_weights.erase(truck_weights.begin());
        }
    }
    return answer;



    return 0;
}