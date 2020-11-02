#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n , m;
    cin >> n;
    int* input_list = new int[n];
    for(int i=0; i<n; i++){
        cin >> input_list[i];
    }
    sort(input_list, input_list+n);
    // load input value in input_list as ascending order;
    cin >> m;
    int* compare_list = new int[m];
    int* result = new int[m];
    for(int i=0; i<m; i++){
        result[i] = 0;
        cin >> compare_list[i];
    }
    
    for(int i=0; i<m; i++){
        int start = 0;
        int end = n-1;
        int comp_val = compare_list[i];
       while(start<=end){
           int mid = (start+end)/2;
           if(input_list[mid] > comp_val){
                end = mid-1;
            }
            else if(input_list[mid] < comp_val){
                start = mid+1;
            }
            else if(input_list[mid] == comp_val){
                result[i] = 1;
                break;
            }
       }
    }
    
    for(int i=0; i<m; i++){
        cout << result[i] << " ";
    }


}