#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int n , cons_k ;
    cin >> n >> cons_k;

    int* input_list = new int[n];
    for(int i=0; i<n; i++){
        cin >> input_list[i];
    }
    long double min_std;
    for(int k=cons_k; k<=n; k++){
    for( int j=0; j<=n-k; j++){
        long double tmp_sum = 0;
        for(int x=0; x<k; x++){
            tmp_sum += input_list[j+x];
        }
        long double avr = tmp_sum / k;
        long double tmp_sum2 = 0;
        for(int x=0; x<k; x++){
            tmp_sum2 += pow((input_list[j+x]-avr),2);
        }
        long double std = sqrt(tmp_sum2/k);
        
        if(k==cons_k && j==0) min_std = std;
        else if( std < min_std) min_std = std;
    }
    }
    //cout.precision(11);
    cout<<min_std;


}