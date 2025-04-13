#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
const int N = 2e5 + 10,mod = 1e9 + 7,inf = 1e18;
void solve(){
    int n;cin >> n;
    vector<vector<char>> a(n + 1,vector<char>(n + 1));
    if(n & 0x1){
        a[(n+1)/2][(n+1)/2] = 'U';
    }
    int k = n - 1;
    for(int i=1;n>1&&i<=k;i++){
        a[i][1] = 'D';
        a[n][i] = 'R';
        a[n-i+1][n] = 'U';
        a[1][n-i+1] = 'L';
    }
    for(int i=2;i<=n/2;i++){
        int k = n - (i - 1) * 2 - 1;
        int sx = i,sy = i;
        for(int i=0;i<k;i++){
            a[sx+i][sy] = 'L';
            a[sx+k][sy+i] = 'D';
            a[sx+k-i][sy] = 'R';
            a[sx][sy+k-i] = 'U';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j] << "\n"[j==n];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}