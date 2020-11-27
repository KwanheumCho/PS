#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct s_type{
    int a, b, c;
    string name;
};


bool comp(s_type A, s_type B){
    if(A.a != B.a){
        return A.a > B.a;
    }
    else if(A.b != B.b){
        return A.b < B.b;
    }
    else if(A.c != B.c){
        return A.c > B.c;
    }
    else {
        return A.name < B.name;
    }

}

int main(void){
    int N;
    cin >> N;
    vector< s_type > v;
    for(int i=0; i<N; i++){
        string name;
        int a, b, c;
        cin >> name >> a>> b >> c;
        s_type tmp = {a, b, c, name};
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), comp);
    for(int i=0; i<v.size(); i++){
        cout << v[i].name << '\n';
    }
}