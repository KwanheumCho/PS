#include <iostream>
#include <string>
using namespace std;

int main(void){
    string input;
    cin >> input;
    //cout << input.length() << endl; // input's length
    
    string tmp1 = "";
    string tmp2 = "";
    long long result=0;
    int Flag = 1;
    for(int i=0; i<input.length(); i++){
        if(input[i] != '+' && input[i] != '-'){
            tmp1.push_back(input[i]);
            //cout << tmp1 << endl;
        }
        else if(input[i] == '+'){
            result += stoi(tmp1) * Flag;
            tmp1 = "";
        }
        else if(input[i] == '-'){
            result += stoi(tmp1) * Flag;
            tmp1 ="";
            if(Flag == 1) Flag = -1;
        }
        if( i == input.length()-1) result += stoi(tmp1) * Flag;
    }
    cout << result << endl;
}