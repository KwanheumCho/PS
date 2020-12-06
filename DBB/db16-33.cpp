#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




int main(void){
    int n;
    cin >> n;
    vector<pair<int, int> > v[16];
    for(int i=1; i<=n; i++){
        int t, p;
        cin >> t >> p;
        if(i+t-1 <= n ) v[i+t-1].push_back({t, p});
    }
    int dp[16] = {0, };

    for(int i=1; i<=n; i++){ 

        for(int j=0; j<v[i].size(); j++){
            int before_time = v[i][j].first;
            int cost = v[i][j].second;
            dp[i] = max(dp[i], dp[i-before_time] + cost);
        }
        dp[i] = max(dp[i],  dp[i-1]);
        //cout <<"i: "<<i<<" " <<dp[i] << endl;
    }
    cout << dp[n] << endl;
}