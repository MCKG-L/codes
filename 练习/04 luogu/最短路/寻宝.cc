#include <iostream>
using namespace std;
const int N = 105,M = 10005;
int d[N][N];
int a[M];
int m,n,ans;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j] = min(d[i][k] + d[k][j],d[i][j]);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> d[i][j];
        }
    }
    floyd();
    for(int i=1;i<m;i++){
        ans += d[a[i-1]][a[i]];
    }
    cout << ans << endl;
    return 0;
}
