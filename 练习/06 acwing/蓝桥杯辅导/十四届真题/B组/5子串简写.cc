#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 55;
typedef pair<int,int> PII;

// void solve(){
//     int k;cin >> k;
//     string s;cin >> s;
//     s = ' ' + s;
//     char a,b;
//     cin >> a >> b;
//     int ans = 0,cnt = 0;
//     for(int i=k;i<=s.size();i++){
//         if(s[i-k+1] == a) cnt ++;
//         if(s[i] == b) ans += cnt;
//     }
//     cout << ans << endl;
// }
void solve(){
    int k;cin >> k;
    string s;cin >> s;
    s = ' ' + s;
    char a,b;cin >> a >> b;
    int n = s.size() - 1;
    vector<int> cnt(n+1);
    for(int i=1;i<=n;i++){
        cnt[i] = cnt[i-1];
        if(s[i] == a) cnt[i] ++;
    }
    int ans = 0;
    for(int i=k;i<=n;i++){
        if(s[i] == b){
            cout << "i:" << i << endl;
            cout << "cnt:" << cnt[i-k+1] << endl;
            ans += cnt[i-k+1];
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