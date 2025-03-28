#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 30;
int a[N][N],b[N][N];
int c[N][N];
void solve(){
    int n,m;cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cin >> b[i][j];
        }
    }
    for(int i=1;i+n-1<=m;i++){
        for(int j=1;j+n-1<=m;j++){
            int sum = 0;
            for(int ii=1;ii<=n;ii++){
                for(int jj=1;jj<=n;jj++){
                    sum += a[ii][jj] * b[i+ii-1][j+jj-1];
                }
            }
            c[i][j] = sum;
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
    
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}