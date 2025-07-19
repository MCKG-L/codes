#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10,mod = 998244353,inf = 1e18;
/* abc_377_e
给你一个排列 P=(P1​,P2​,…,PN​)
下面的操作将进行 K 次：
    对于 i=1,2,…,N ，同时将 Pi​ 更新为 PPi​​ 。
操作完成后输出 P 。

模拟过程可以发现是一个环的问题，进行k次操作，相当于在换上移动2^k-1次
对环的长度取模
*/
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<bool> st(n + 1);
    auto qmi = [&](int a,int k,int mod)->int{
        int res = 1ll;
        while(k){
            if(k & 0x1) res = res * a % mod;
            k >>= 1;
            a = a * a % mod;
        }
        return res;
    };
    vector<int> ans(n + 1);
    for(int i=1;i<=n;i++){
        if(st[a[i]]) continue;
        int u = a[i];
        vector<int> p;
        while(!st[u]){
            p.push_back(u);
            st[u] = 1;
            u = a[u];
        }
        int d = qmi(2,k,p.size());
        for(int i=0;i<p.size();i++){
            ans[p[i]] = p[(i+d-1)%p.size()];
        }
    }
    for(int i=1;i<=n;i++) cout << ans[a[i]] << ' ';
    cout << endl;
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