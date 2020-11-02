#include <iostream>
#include <vector>
#include <utility>
#define MAX_SIZE 100
using namespace std;

struct node{
    int x;
    int y;
};

int main(void){
    vector< pair<int,int>> input;
    input.push_back(make_pair(1,2));
    input.push_back(make_pair(2,3));
    input.push_back(make_pair(3,4));
    input.push_back(make_pair(2,1));
    input.push_back(make_pair(4,3));
    bool chk[MAX_SIZE][MAX_SIZE]={false,};
    vector< pair<int,int>> answer;
    for(int i=0; i< input.size(); i++){
        int row = input[i].first;
        int col = input[i].second;
        chk[row][col] = true;
    }
    for(int i=0; i< input.size(); i++){
        int row = input[i].first;
        int col = input[i].second;
        if(chk[col][row]) answer.push_back(input[i]);
    }
    for(int i=0; i<answer.size(); i++){
        cout << answer[i].first << " "<<answer[i].second << endl;
    }

    return 0;
}