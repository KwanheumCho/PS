#include <iostream>
#include <map>
using namespace std;

int main(void){
    int test_case;
    cin >> test_case;
    int* result = new int[test_case];
    for(int i=0; i<test_case;i++){
        int n;
        cin >> n;
        int* array = new int[n+1]; // i dont use index 0;
        int tmp1, tmp2;
        for(int j=1; j<=n; j++){
            cin >> tmp1 >> tmp2;
            array[tmp1] = tmp2;
        }
        int bound;
        int tmp_result = 1;
        bound = array[1];
        for(int j=2; j<=n; j++){
            if(array[j] < bound){
                tmp_result++;
                bound = array[j];
                }
        }
        result[i] = tmp_result;
    }
    for(int i=0; i<test_case;i++){
        cout<<result[i]<<endl;
    }

}