#include <iostream>
using namespace std;

int min(int a, int b){
    if(a < b)
        return a;
    else
    {
        return b;
    }
}


int N, M, H;
bool ladder[31][11]; // 1<= H <= 30 , 2<=N<=10
bool content[31][11];
int ans = -1;
void add(int h, int n){
        ladder[h][n] = true;
        ladder[h][n+1] = true;
        content[h][n] = true;
}
bool check(){
    int tmp;
    for(int col=1; col<=N; col++){
        tmp = col;
        for(int row=1; row<=H; row++){
            if(tmp ==1){
                if(ladder[row][col]) tmp++;
            }
            else if(tmp<col){
                if(ladder[row][tmp-1]) tmp--;
                else if(ladder[row][tmp]) tmp++;
            }
            else if(tmp == col){
                if(ladder[row][tmp-1]) tmp--;
            }
        }
        if(tmp != col) return false;
    }
    return true;
}

void solve(int a, int b, int c){
    
    
    
    bool tmp[31][11];
    bool tmp2[31][11];
    for(int i=1; i<=H; i++){
        for(int j=1; j<=N; j++){
            tmp[i][j] = ladder[i][j];
            tmp2[i][j] = content[i][j];
        }
    }
    
    if(ladder[a][b] == false && ladder[a][b+1] == false){
        
        add(a, b);
        c += 1;
        //cout<< "a: "<<a << "b:" << b <<"c: "<<c<<" ans: "<<ans<<"check: "<<check()<<endl;
        if(a==6 && b==2 && c==2 && check()){
            if(ans == -1)
                {ans = c;
                //cout<< "1a: "<<a << "b:" << b <<"c: "<<c<<" ans: "<<ans<<endl;
                return;}
            else
            {
                //cout<< "2a: "<<a << "b:" << b <<"c: "<<c<<" ans: "<<ans<<endl;
                ans = min (ans, c);
                if(ans > 3) ans = -1; return;
            }
        }
        if(b<N-1) solve(a, b+1, c);
        else if(a<H) solve(a+1, 1, c);
        
        if(b<N-1){
            for(int i=1; i<=H; i++){
                for(int j=1; j<=N; j++){
                    ladder[i][j] = tmp[i][j];
                    content[i][j] = tmp2[i][j];
                }
            }
            solve(a,b+1, c-1);
        }
        else if(a<H){
            for(int i=1; i<=H; i++){
                for(int j=1; j<=N; j++){
                    ladder[i][j] = tmp[i][j];
                    content[i][j] = tmp2[i][j]; 
                }
            }
            solve(a+1, 1, c-1);}
        
    }
    else{
        if(b<N-1) solve(a,b+1,c);
        else if(a<H) solve(a+1, 1, c);
    }

}

int main(void){
    cin >> N >> M >> H;
    //ladder initialization
    for(int i=1; i<=H; i++){
        for(int j=1; j<=N; j++){
            ladder[i][j] = false;
            content[i][j] = false;
        }
    }
    for(int k=0; k<M; k++){
        int row, col;
        cin >> row >> col;
        ladder[row][col] = true; ladder[row][col+1]= true;
        content[row][col] = true;
    }
    solve( 1, 1, 0);
    cout << ans << endl;


    


    return 0;
}