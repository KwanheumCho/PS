#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int dx[21];
int dy[21];
int T;
int num_pos;
bool chk[20] = {false,};
double min_chk;
void func(int cnt, int start){
    if(cnt == num_pos/2){
        int x_pos =0;
        int y_pos = 0;
        for(int j=0; j<num_pos; j++){        
            if(chk[j]==false){
                x_pos -= dx[j];
                y_pos -= dy[j];
            }
            else{
                x_pos += dx[j];
                y_pos += dy[j];
            }
        }
        
        double result = sqrt(pow(x_pos,2) + pow(y_pos,2));
        if(min_chk > result) {
            min_chk = result;
        }
        return;
    }
    if(start >= num_pos) return;
            for(int j=start; j<num_pos; j++){
                chk[j] = true;
                func(cnt+1, j+1);
                chk[j] = false;
            }
    
}

/*
void func(vector<pos> points, pos before, int cnt, vector<pos> tmp){
    if(cnt == points.size()){
        int x_pos=0;
        int y_pos=0;
        for(int i=0; i< tmp.size(); i++){
            x_pos += tmp[i].x;
            y_pos += tmp[i].y;
        }
        double result = sqrt(pow(x_pos,2) + pow(y_pos,2));
        if(min_chk > result) {
            min_chk = result;
        }
        return;
    }
    for(int j=0; j<points.size(); j++){
        if(chk[j] != true){
            chk[j] = true;
            if((cnt+1)%2 ==0){
                pos v{points[j].x - before.x , points[j].y - before.y};
                tmp.push_back(v);
                pos garbage{0,0};
                func(points, garbage, cnt+1, tmp);
                tmp.pop_back();
            }
            else{
                func(points, points[j], cnt+1, tmp);
            }
            chk[j] = false;
        }
    }
    
}
*/

int main(void){
    //int T;
    cin >> T;
    vector<double> answer;
    for(int i=0; i<T; i++){
        //vector<pos> points;
        int result = 0;
        //int num_pos;
        cin >> num_pos;
        for(int j=0; j<num_pos; j++){
            //pos A;
            cin >> dx[j] >> dy[j] ;
            //points.push_back(A);
            chk[j] = false;
        }
        min_chk = 1000000000.0;
        //vector<pos> tmp;
        //func(points, {0,0}, 0, tmp);
        //func(points, 0, 0, 0);
        func(0, 0);
        answer.push_back(min_chk);
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout<<fixed;
    cout.precision(12);
    for(int i=0; i<answer.size(); i++){    
        cout << answer[i] << '\n';
    }
}