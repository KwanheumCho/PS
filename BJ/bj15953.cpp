#include <iostream>
using namespace std;

int main(void){
    int case_number;
    cin >> case_number;
    int* result = new int[case_number];



    for(int j=0; j<case_number; j++){
        int a , b;
        int tmp_result=0;
        cin >> a >> b;
        if (a==0) tmp_result+=0;
        else if(a==1) tmp_result+=500;
        else if(a<=3) tmp_result+=300;
        else if(a<=6) tmp_result+=200;
        else if(a<=10) tmp_result+=50;
        else if(a<=15) tmp_result+=30;
        else if(a<=21) tmp_result+=10;

        if (b==0) tmp_result+=0;
        else if(b==1) tmp_result+=512;
        else if(b<=3) tmp_result+=256;
        else if(b<=7) tmp_result+=128;
        else if(b<=15) tmp_result+=64;
        else if(b<=31) tmp_result+=32;

        result[j] = tmp_result*10000;
    }
    for(int j=0; j<case_number; j++){
        cout<<result[j]<<endl;
    }


}