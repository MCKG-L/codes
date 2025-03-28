#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++){
        string s;cin >> s;
        bool f = 1;
        for(int j=0;j<s.size();j++){
            if(isdigit(s[j])){
                int x = 0;
                while(isdigit(s[j])) x = x * 10 + s[j] - '0',j ++;
                if(x > 255) f = 0;
            }
        }
        if(f) ans ++;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}