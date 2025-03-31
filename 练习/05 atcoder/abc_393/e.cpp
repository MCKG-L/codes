#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1e6 + 10,inf = 1e18;
int p[N],idx;
bool st[N];
void getPrimes(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) p[idx++] = i;
        for(int j=0;p[j]<=n/i;j++){
            st[p[j]*i] = 1;
            if(i % p[j] == 0) break;
        }
    }
}
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    int M = *max_element(a.begin(),a.end());
    vector<int> s(M+1),cnt(M+1),ans(M+1);
    for(auto x : a) s[x] ++;
    for(int d=1;d<=M;d++){
        for(int i=d;i<=M;i+=d){
            cnt[d] += s[i]; //d的倍数的个数
        }
    }
    //当d的倍数数目不小于k时，ans[k*d] = d
    for(int d=1;d<=M;d++){
        if(cnt[d] < k) continue;
        for(int i=d;i<=M;i+=d){
            ans[i] = max(ans[i],d);
        }
    }
    for(int i=0;i<n;i++) cout << ans[a[i]] << '\n';
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