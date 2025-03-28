#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int mod = 1e9 + 7;
using ll = long long;
typedef pair<int,int> PII;
int a[N][N];
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            a[i][j] += a[i-1][j];//列方向上的前缀和
        }
    }
    //枚举上线边界 双指针求左右边界
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int s = 0,r = 1,l = 1;
            while(r <= m){
                s += a[j][r] - a[i-1][r];
                while(l <= r && s > k) s -= a[j][l] - a[i-1][l], l ++;
                ans += r - l + 1;
                r ++;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}