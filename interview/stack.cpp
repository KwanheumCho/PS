#include <iostream>
#include <stack>
using namespace std;

void Error(){
    cout << "=> Wrong!!" << endl;
}

int main(void){
    stack<char> st;
    char c;
    for(int i=0; i<6; i++){
        cin >> c;
        if(c==')' || c=='}' || c==']'){
            if(st.empty()){
                Error();
                return -1;
            }
            if( (c==')'&& st.top() =='(') ||
            (c=='}'&& st.top() =='{') ||
            (c==']'&& st.top() =='[') 
            ){
                st.pop();
                // pop => void , so if you want to check entity then use top
                // ex) st.top();
                continue;
            }
        }
        st.push(c);
    }
    if(!st.empty()){
        Error();
        return -1;
    }

    cout << "=> Correct!!" << endl;
    return 0;
}