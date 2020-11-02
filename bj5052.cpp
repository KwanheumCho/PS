#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    int T;
    cin >> T;
    vector<string> phone_list;
    vector<string> result_list;
    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        string tmp;
        for(int j=0; j<N; j++){
            cin >> tmp;
            phone_list.push_back(tmp);
        }
        sort(phone_list.begin(), phone_list.end());
        /*
        for(int k=0; k<phone_list.size(); k++){
            cout << phone_list[k] << endl;
        }
        cout << endl;
        */
       bool flag;
        for(int x=0; x<phone_list.size()-1; x++){
            int len;
            flag = false; // false면 일관성이 없음을 의미.
            if(phone_list[x].size() < phone_list[x+1].size()){
                len = phone_list[x].size();
            }
            else len = phone_list[x+1].size();
            for(int y=0; y<len; y++){
                if(phone_list[x][y] != phone_list[x+1][y]){
                    flag = true;
                    break;
                    }
            }
            if(!flag) {
                result_list.push_back("NO");
                break;
                }
            else if(x==phone_list.size()-2) result_list.push_back("YES");
        }
        phone_list.clear();
    }//T for
    for(int i=0; i<result_list.size(); i++){
        cout << result_list[i] << endl;
    }
}