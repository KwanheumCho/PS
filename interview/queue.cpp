#include <iostream>
#include <queue>
using namespace std;

int main(void){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.pop();
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    // pop => void type , so if you want to check entity then use top
    // ex) q.front();
    return 0;

}