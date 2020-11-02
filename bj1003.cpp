#include <iostream>
using namespace std;

int main(void){
    int zero_count[41];
    int one_count[41];
    zero_count[0] = 1;
    zero_count[1] = 0;
    one_count[0] = 0;
    one_count[1] = 1;
    for(int i=2; i<41; i++){
        zero_count[i] = zero_count[i-1] + zero_count[i-2];
        one_count[i] = one_count[i-1] + one_count[i-2];
    }
    int case_number , n ;
    cin >> case_number;
    int* case_set = new int[case_number];
    for(int k=0; k<case_number; k++){
        cin >> n;
        case_set[k] = n; 
    }
    for(int k=0; k<case_number; k++){
        cout << zero_count[case_set[k]] << " " << one_count[case_set[k]] << endl;
    }
    return 0;
}