#include <iostream>
#include <string>
#include <vector>
using namespace std;

void func(int* arr, int start, vector<int> result){

    for(int i=0; i< result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    if(start > 3) return;
    for(int i=start; i<3; i++){
        result.push_back(arr[i]);
        func(arr, i+1, result);
        result.pop_back();
    }
    return;

}

int main(void){

    int arr[] = {1, 2, 3};
    vector<int> result;
    func(arr, 0, result);

}