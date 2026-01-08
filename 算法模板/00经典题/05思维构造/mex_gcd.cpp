#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 3e5 + 10,M = 32,mod = 1e9 + 7,inf = 1e18;
/*
小度熊有 n 个非负整数 a1,a2,…,an​。小度熊需要你选择 k 个数组成一个可重集合 S，
求 S 的 gcd 和 mex 的异或和的最大值。
同时，他希望你对于 k=1,2,⋯ ,n均求出答案。
gcd(0,4,6)=2 特殊地，定义任意多个 0 的 gcd⁡ 为 0
对mex和gcd的直观理解：选的数越小，mex越大的可能性增大，gcd越小
两者是一个相斥的概念
可以对mex的取值进行分类讨论：
mex=0时，即需最大化gcd。转化为选k个数使得gcd最大的问题 可以通过迪利克雷后缀来解决
mex=1时，需最大化gcd^1,gcd同样需要尽可能大。问题与mex=0时类似
mex>=2时，0、1必选，则gcd必为1，此时需要最大化mex^1,mex尽可能大

对三种情况分类讨论即可，需要特判全为0的情况
*/
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1),cnt(1e6 + 10);
    int mx = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        mx = max(mx,a[i]);
        cnt[a[i]] ++;
    }
    if(cnt[0] == n){
        for(int i=1;i<=n;i++){
            cout << 1 << ' ';
        }
        cout << endl;
        return;
    }
    vector<int> d(mx + 1);
    for(int i=1;i<=mx;i++){
        for(int j=i;j<=mx;j+=i) d[i] += cnt[j];
    }
    vector<int> mxgcd(n + 1);//
    int idx = 1;
    for(int i=mx;i>=1;i--){
        if(d[i] >= idx){
            while(idx <= d[i]){
                mxgcd[idx++] = i;
            }
        }
    }
    int Mmex = 0;
    for(int i=0;i<=mx;i++){
        if(cnt[i]){
            Mmex = i + 1;
        }else{
            break;
        }
    }
    vector<int> ans(n + 1);
    for(int i=1;i<=n;i++){
        //mex == 0
        if(n - cnt[0] >= i){
            ans[i] = max(ans[i],mxgcd[i]);
        }
        //mex == 1
        if(i >= 2 && cnt[0] && n - cnt[1] >= i){
            int gcd = mxgcd[max(1ll,i-cnt[0])];
            ans[i] = max(ans[i],gcd^1);
            //(gcd-1)^1
            if(d[gcd-1] >= max(1ll,i-cnt[0])){
                ans[i] = max(ans[i],(gcd-1)^1);
            }
        }
        //mex >= 2, gcd=1
        if(i >= 2 && cnt[0] && cnt[1]){
            int mex = i < Mmex ? i : Mmex;
            ans[i] = max(ans[i],mex ^ 1);
            //(mex-1)^1
            if(n-cnt[mex-1]>=i){
                ans[i] = max(ans[i],(mex-1)^1);
            }
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << ' ';
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
