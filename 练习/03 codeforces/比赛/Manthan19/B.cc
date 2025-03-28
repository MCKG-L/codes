#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = 1e9;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        bool f = 1;mp.clear();
        for(int j=0;j<i;j++){
            if(mp[a[j]]){
                f = 0;break;
            }
            else mp[a[j]] ++;
        }
        int pos = n;
        for(int j=n-1;j>=i;j--){
            if(mp[a[j]])  break;
            else{
                pos = j;
                mp[a[j]] ++;
            }
        }
        if(f) ans = min(ans,pos-i);
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