#include <iostream>
using namespace std;

int main(void){
    int input_number;
    cin >> input_number; // input_number <= 1000
    int result = 0;
    for(int j=1; j<input_number+1; j++){
        if(j < 100)
            {result++;}
        else if(j < 1000)
        {
            int a = j/100;
            int b = (j%100)/10;
            int c = (j%100)%10;
            if( a-b == b-c)
                result++;
        }
        
    }
    cout<<result<<endl;
}