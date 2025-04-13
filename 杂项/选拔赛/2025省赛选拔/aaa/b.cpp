#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
const int N = 2e5 + 10,mod = 1e9 + 7,inf = 1e18;
void solve(){
    unordered_map<int,int> mp;
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        mp[a[i]] ++;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(!mp.count(a[i] | a[j])){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
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