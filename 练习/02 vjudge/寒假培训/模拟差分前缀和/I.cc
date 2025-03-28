#include <bits/stdc++.h>
using namespace std;
/*
二维前缀和 滑动窗口
*/
int main()
{
    int n,m,c;
    cin >> n >> m >> c;
    vector<vector<int>> a(n+1,vector<int>(m+1)),b(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> b[i][j];
            a[i][j] = a[i-1][j]+a[i][j-1]+b[i][j]-a[i-1][j-1];
        }
    }
    int x,y;
    int maxn = -1e9;
    for(int i=c;i<=n;i++){
        for(int j=c;j<=m;j++){
            if(a[i][j]+a[i-c][j-c]-a[i][j-c]-a[i-c][j] > maxn){
                maxn = a[i][j]+a[i-c][j-c]-a[i][j-c]-a[i-c][j];
                x = i - c + 1;
                y = j - c + 1;
            }
        }
    }
    cout << x << " " << y;
    return 0; 
}