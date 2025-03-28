#include <bits/stdc++.h>
using namespace std;
const int N = 40;
int a[N][N];
int main()
{
    int n;cin >> n;
    int x = 1;
    int y = (n + 1) / 2;
    int xx = x,yy = y;
    a[x][y] = 1;
    for(int i=2;i<=n*n;i++){
        if(xx == 1 && yy < n){
            x = n;
            y = yy + 1;
        }
        if(yy == n && xx > 1){
            x = x - 1;
            y = 1; 
        }
        if(xx == 1 && yy == n){
            x = xx + 1;
            y = yy;
        }
        if(xx > 1 && yy < n){
            if(a[xx-1][yy+1]==0){
                x = xx - 1;
                y = yy + 1;
            }else{
                x = xx + 1;
                y = yy;
            }
        }
        a[x][y] = i;
        xx = x;
        yy = y;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j] << " \n"[j == n];
        }
    }
    return 0;
}