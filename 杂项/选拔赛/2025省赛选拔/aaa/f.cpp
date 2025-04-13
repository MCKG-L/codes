#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
const int N = 2e5 + 10,mod = 1e9 + 7,inf = 1e18;
void solve(){
    int n;cin >> n;
    vector<int> cnt(n + 1);
    vector<int> alls;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        cnt[x] ++;
        if(cnt[x] == 2){
            alls.push_back(x);
            cnt[x] = 0;
        }
    }
    sort(alls.begin(),alls.end());
    int ans = 0;
    for(int i=alls.size()-1;i-1>=0;i-=2){
        ans += alls[i] * alls[i-1];
    }
    cout << ans << endl;
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