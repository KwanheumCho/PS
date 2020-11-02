#include <iostream>
using namespace std;

int main(void){
    long long x, y;
    cin >> x >> y;
    long long tmp_z;
    tmp_z = (y*100) / x ;
    int z = (int)tmp_z;
    //cout<<"z: " << z << endl;
    long long counter = 0;
    if( z >= 99)
        {
            cout<<-1<<endl;
        }
    else{
        long long first = 1;
        long long last = 1000000000;
        long long mid, result;
        while(first<=last){
            mid = (first + last) / 2;
            int next_z = ( (y+mid)*100 / (x+mid) );
            if ( z < next_z){
                last = mid-1, result = mid;
                //cout<<"98result: "<<result<<endl;
            }
            else first = mid+1;
        }
        cout << result << endl;
    }

}