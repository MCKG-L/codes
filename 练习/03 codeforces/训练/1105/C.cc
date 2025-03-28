#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,mod = 998244353;
int fac[N],infac[N];
int qmi(int a,int k){
    int ans = 1ll;
    while(k){
        if(k & 1) ans = ans * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return ans;
}
void init(){
    fac[0] = infac[0] = 1;
    for(int i=1;i<=N;i++){
        fac[i] = fac[i-1] * i % mod;
        infac[i] = infac[i-1] * qmi(i,mod-2) % mod;
    }
}
int C(int a,int b){
    if(a < b) return 0;
    int ans = 1ll;
    ans = fac[a] * infac[b] % mod * infac[a-b] % mod;
    return ans;
}
/*
隔板法 
1、考虑将k列含黑色的列分为d块，不同块之间不相邻（有全白列相隔）
用隔板法可知，共有C(k-1,d-1)种分法
2、剩余有n-k个全白列，即d个黑色块将被这n-k个白色分隔
插空法 即有d个不相邻块
用插空法可知，共有C(n-k+1,d)种插入方法
3、不同的黑色块之间(不相邻)互不影响，每一个黑色块有两种摆法，则共有2^d种摆法
枚举黑色块的个数，相加得到答案
*/
void solve(){
    int n,k;
    cin >> n >> k;
    if(k == 0){
        cout << 1 << endl;
        return;
    }
    int ans = 0ll;
    for(int i=1;i<=k;i++){
        ans = (ans + qmi(2,i)*C(k-1,i-1)%mod*C(n-k+1,i)%mod) % mod;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;init();
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}