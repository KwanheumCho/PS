#include <iostream>

using namespace std;



int main()
{
    int input, number;
    cin >> input;
    int list[11]; // number range is 1~10
    list[1] = 1; // 1 = 1
    list[2] = 2; // 2 = 1 + 1 , 2
    list[3] = 4; // 3 = 1 + 1+ 1, 1+2, 2+1, 3
    for(int i=4; i<11; i++){
        list[i] = list[i-1] + list[i-2] + list[i-3];
    }
    int* result = new int[input];
    for(int k = 0; k <input; k++){
        cin >> number;
        result[k] = list[number];
    }
    for(int j=0; j<input; j++){
        cout << result[j] << endl;
    }
    delete[] result;
    return 0;
}