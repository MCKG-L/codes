#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    string ans;
    vector<int> a(n);
    int mx = -1;
    for(int i=0;i<n;i++){
        string name;int x;
        cin >> name >> x;
        if(x > mx) ans = name,mx = x;
        a[i] =  x;
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i] == mx) cnt ++;
    }
    if(cnt > 1) cout << "wake up, Third!" << endl;
    else cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}