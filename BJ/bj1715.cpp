#include <iostream>
#include <queue>
using namespace std;

int main(void){
    int N;
    cin >> N;
    priority_queue<int ,vector<int>, greater<int> > q; //디폴트(내림차순)에서 오름차순으로 변환.
    //혹은 디폴트 우선순위큐에서 q에 값을 집어넣을때 음수(-)로 바꿔서 집어넣으면, 큰값이 음수일땐 더 작아져서 자동적으로 우선순위큐에서 아랫쪽에 위치.
    // 꺼낸다음에 다시 (-)를 취해주면 원래 값을 유지.
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