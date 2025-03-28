#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
// using ll = long long;
#define int long long
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<PII> a(n+1);
    vector<int> s(n+1),pre(n+1),ans(n+1);
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        a[i] = {x,i};
    }
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1] + a[i].first;
    }
    s[n] = n - 1;
    for(int i=n-1;i>=1;i--){
        PII p = a[i];
        int id = p.second,x = p.first;
        int sum = pre[i];
        int l = i,r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(a[mid].first <= sum) l = mid;
            else r = mid - 1;
        }
        s[i] = max(i-1,s[l]);
    }
    for(int i=1;i<=n;i++){
        auto [x,id] = a[i];
        ans[id] = s[i];
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}