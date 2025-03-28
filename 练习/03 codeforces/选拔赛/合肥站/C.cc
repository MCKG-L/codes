#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;

void solve(){
    int n;cin >> n;
    vector<int> a(n+10);
    vector<bool> st(n+10);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(n <= 2){
        cout << 1 << endl;
        return;
    }
    int cnt = 0,ans = 0;
    vector<PII> b;
    while(1){
        ans ++;b.clear();
        for(int i=0;i<n;i++){
            if(st[i]) continue;
            b.push_back({a[i],i});
        }
        int m = b.size();
        for(int i=0;i<m;i++){
            auto [x,id] = b[i];
            if(i == 0 && x < b[i+1].first){
                st[id] = 1;cnt ++;
            }else if(i == m - 1 && x < b[i-1].first){
                st[id] = 1;cnt ++;
            }else{
                if(x < b[i-1].first || x < b[i+1].first){
                    st[id] = 1;cnt ++;
                }
            }
        }
        if(n - cnt <= 2) break;
    }
    if(n - cnt >= 2) ans ++;
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}