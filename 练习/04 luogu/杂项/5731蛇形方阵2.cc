#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int ans[N][N];
int main()
{
    int n;cin >> n;
    int x = 1,y = 0,k = 1;
    while(k <= n * n){
        while(y+1<=n&&ans[x][y+1]==0) ans[x][++y] = k++;
        while(x+1<=n&&ans[x+1][y]==0) ans[++x][y] = k++;
        while(y-1>=1&&ans[x][y-1]==0) ans[x][--y] = k++;
        while(x-1>=1&&ans[x-1][y]==0) ans[--x][y] = k++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%3d",ans[i][j]);
        }
        cout << endl;
    }
    return 0;
}