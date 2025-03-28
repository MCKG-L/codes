#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;cin >> n >> m;
    int a[n+2][n+2];
    memset(a,0,sizeof(a));
    for(int i=1;i<=m;i++){
        int x1,x2,y1,y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        a[x2+1][y2+1]++;
        a[x1][y1]++;
        a[x2+1][y1]--;
        a[x1][y2+1]--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            cout << a[i][j] << " \n"[j == n];
        }
    }
    return 0;
}