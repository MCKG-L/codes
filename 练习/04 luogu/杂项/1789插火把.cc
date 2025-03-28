#include <iostream>
using namespace std;
const int N = 105;
int a[N][N];
void fun1(int x,int y,int n){
    for(int i=-2;i<=2;i++){
        int xx = max(1,x+i);
        int yy = max(1,y+i);
        a[xx][y] = a[x][yy] = 1;
        
    }
    a[max(1,x-1)][max(1,y-1)] = 1;
    a[x+1][max(1,y-1)] = 1;
    a[max(1,x-1)][y+1] = 1;
    a[x+1][y+1] = 1;
}
void fun2(int x,int y,int n){
    for(int i=max(1,x-2);i<=x+2;i++){
        for(int j=max(1,y-2);j<=y+2;j++){
            a[i][j] = 1;
        }
    }
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        fun1(x,y,n);
    }
    for(int i=1;i<=k;i++){
        int x,y;
        cin >> x >> y;
        fun2(x,y,n);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j] == 0){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}