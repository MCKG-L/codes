#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int f[N];//考虑前i天，可以获得的最大增益
int k[N],s[N],pre[N];
int n,m,q;
bool st[N];
/*
要求同一天不能同时进行两个及以上的训练 所以不是完全背包 属于线性dp
考虑1~i可以满足的最大值 转移方程：f[i] = max(f[i],f[i-len] + s[j]);
*/
void solve(){
    cin >> n >> m >> q;
    for(int i=0;i<q;i++){
        int x;cin >> x;
        pre[x] = 1;
        st[x] = 1;
    }
    for(int i=1;i<=m;i++){
        cin >> k[i] >> s[i];
    }
    for(int i=1;i<=n;i++) pre[i] += pre[i-1];//使用前缀和 判断一段区间是否可用
    for(int i=1;i<=n;i++){
        f[i] = f[i-1];
        if(st[i]) continue;//第i天不能训练 f[i] = f[i-1];
        for(int j=1;j<=m;j++){ //枚举所有训练计划
            int len = (1 << k[j]);
            if(len > i || pre[i] != pre[i-len]) continue;//不能安排计划j
            f[i] = max(f[i],f[i-len] + s[j]);
        }
    }
    cout << f[n] << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}