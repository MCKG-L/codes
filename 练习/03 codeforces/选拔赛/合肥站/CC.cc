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
        int x;cin >> x;
        a[i] = x;
    }
    int cnt = 0,ans = 0;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    if(n <= 2){
        cout << 1 << endl;
        return;
    }
    while(1){
        ans ++;
        vector<PII> b;
        for(int i=0;i<n;i++){
            int x = a[i];
            if(st[x]) continue;
            b.push_back({x,i});
        }
        if(b.size() == 1){
            ans --;
            break;
        }
        for(int i=0;i<b.size();i++){
            auto [x,id] = b[i];
            if(i == 0){
                if(x < b[i+1].first){
                    st[x] = 1;cnt ++;
                }
            }else if(i == b.size() - 1){
                if(x < b[i-1].first){
                    st[x] = 1;cnt ++;
                }
            }else{
                if(x < b[i-1].first || x < b[i+1].first){
                    st[x] = 1;cnt ++;
                }
            }
        }
    }
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