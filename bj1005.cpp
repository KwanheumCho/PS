#include <iostream>
#include <vector>
using namespace std;

void dp_func( vector<int>* buildup, int* dp, int* time_list ,int start){
            int x = start;
            int pre_numb = buildup[x].size();
            int max_val = 0;
            for(int y=0; y<pre_numb; y++){
                int index = buildup[x][y];
                if(dp[index] == -1) dp_func(buildup , dp, time_list, index);
                if(max_val < dp[index]){
                    max_val = dp[index];
                }
            }
            dp[x] = max_val + time_list[x];
            
        }

int main(void){
    int T;
    cin >> T;
    vector<int> result;
    for(int i=0; i<T; i++){
        int N, K;
        cin >> N >> K;
        int* time_list = new int[N+1];
        int* dp = new int[N+1];
        for(int j=1; j<=N; j++){
            cin >> time_list[j];
            dp[j] = -1;
        }
        vector<int>* buildup = new vector<int>[N+1];
        for(int k=0; k<K; k++){
            int a , b;
            cin >> a >> b;
            buildup[b].push_back(a);
        }
        int target;
        cin >> target;
        
        
        for(int x=1; x<=N; x++){
            dp_func(buildup , dp, time_list, x);
            /*
            int pre_numb = buildup[x].size();
            int max_val = 0;
            for(int y=0; y<pre_numb; y++){
                int index = buildup[x][y];
                if(dp[index] == -1) dp_func(buildup , dp, time_list, index); // x번 건물 처리할때 index건물의 dp가 설정 안되어있는 경우 처리.
                if(max_val < dp[index]){
                    max_val = dp[index];
                }
            }
            dp[x] = max_val + time_list[x];
            */
        }

        result.push_back(dp[target]);
        
    } // T for

    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}