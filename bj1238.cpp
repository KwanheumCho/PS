#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001] = {0,};
vector<int> graph[1001];

int find_way(int from, int to){
    if(dp[from][to] ==0){ //가는 길이 없다
        int min = 10000000;
        for(int i=0; i<graph[to].size();i++){
           int before_to = graph[to][i];
           int value = find_way(from, before_to) + dp[before_to][to];
           //cout <<"here: "<< from<<" "<<before_to<<" "<<find_way(from,before_to)<<endl;
           if(min > value){
               min = value;
           }
        }
        return min;
    }
    else{ // 가는길이 있다면, 바로가는길과 돌아가는길 비교해야한다.
        int min = 10000000;
        for(int i=0; i<graph[to].size();i++){
            
            int before_to = graph[to][i];
            cout << "min: "<<min <<" "<<graph[to].size()<<" "<<before_to << " "<< i<< endl;
            if(before_to!= from){
            int value = find_way(from, before_to) + dp[before_to][to];
            //cout <<"here: "<< from<<" "<<before_to<<" "<<find_way(from,before_to)<<endl;
            if(min > value){
                min = value;
                }
            }
            
        }
        if(min > dp[from][to]) return dp[from][to];
        else return min;
    }
}

int main(void){
    int N, M, X;
    cin >> N >> M >> X;
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b>> c;
        dp[a][b] = c;
        graph[b].push_back(a); // b로 가기위한 전단계가 a 이다 라는 뜻

    }
    int max = 0;
    /*
    for(int i=1; i<=N; i++){
        int person = find_way(i, X) + find_way(X, i);
        cout << person << endl;
    }
    */
    cout << find_way(2,3) << endl;
    // n번 학생이 x번 마을로 가는데 걸리는 시간 + 오는데 걸리는 시간

}