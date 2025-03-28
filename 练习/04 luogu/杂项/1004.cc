#include <iostream>
using namespace std;
/*
四维动态规划：连续跑两次二维dp，但是两次不独立
*/
const int N = 10;
int f[N][N][N][N];
int n;
int a[N][N];
int max(int a,int b,int c,int d){
    return (max(max(a,b),max(c,d)));
}
int main()
{
    int x,y,w;
    cin >> n >> x >> y >> w;
    while(1){
        if(!x && !y && !w) break;
        a[x][y] = w;
        cin >> x >> y >> w;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    f[i][j][k][l] = max(f[i-1][j][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+a[i][j]+a[k][l];
                    if(i == k && l == j) f[i][j][k][l] -= a[i][j];
                }
            }
        }
    }
    cout << f[n][n][n][n] << endl;
    return 0;
}