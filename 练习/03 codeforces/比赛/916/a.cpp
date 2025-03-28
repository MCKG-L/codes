#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;\
using ll = long long;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int n;
ll fun2(vector<int> a,vector<int> b,int pos = -1){
    if(pos != -1){
        a[pos] = b[pos] = 0;
    }
    vector<int> lm(n+10),rm(n+10);
    for(int i=1;i<=n;i++) lm[i] = max(lm[i-1],a[i]);
    for(int i=n;i>=1;i--) rm[i] = max(rm[i+1],a[i]);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(i == pos) continue;
        ans = max(ans,b[i] + max(lm[i-1],rm[i+1]));
    }
    lm.clear(),lm.clear();
    lm.resize(n+10,0),rm.resize(n+10,0);
    vector<int> lm2(n+10),rm2(n+10);
    for(int i=1;i<=n;i++) lm[i] = max(lm[i-1],b[i]);
    for(int i=1;i<=n;i++) rm[i] = max(rm[i+1],b[i]);
    for(int i=1;i<=n;i++){
        if(i == pos) continue;
        ans = max(ans,a[i] + max(lm[i-1],rm2[i+1]));
    }
    return ans;
}
ll func(vector<int> a,vector<int> b,vector<int> c){
    int M = 0;
    for(int i=1;i<=n;i++) M = max(M,a[i]);
    vector<int> pos;
    for(int i=1;i<=n;i++){
        if(a[i] == M) pos.push_back(i);
    }
    ll ans = 0;
    if(pos.size() >= 3){
        ans += M;
        ans += fun2(b,c);
    }else{
        ll res = 0;
        for(auto p : pos){
            res = max(res,fun2(b,c,p));
        }
        ans = M + res;
    }
    return ans;
}
void solve(){
    cin >> n;
    vector<int> a(n+10),b(n+10),c(n+10);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) cin >> c[i];
    int ans = 0;
    ans = max({func(a,b,c),func(b,a,c),func(c,a,b)});
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}