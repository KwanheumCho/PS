#include <iostream>
#include <queue>
using namespace std;

int main(void){
    int N;
    cin >> N;
    priority_queue<int ,vector<int>, greater<int> > q;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        q.push(x);
    }
    int result = 0;
    while(q.size()>=2){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        result += a+b;
        q.push(a+b);
    }
    cout << result << endl;

    return 0;
}