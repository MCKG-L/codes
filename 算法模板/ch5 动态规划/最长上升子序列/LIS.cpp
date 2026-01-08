#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e3 + 10,M = 1e5 + 10;
/*朴素做法 O(n^2)
*/
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1),dp(n + 1,-inf);
    for(int i=1;i<=n;i++) cin >> a[i];
    int Max = 0;
    for(int i=1;i<=n;i++){
        dp[i] = 1;
        for(int j=1;j<i;j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        Max = max(Max,dp[i]);
    }
    cout << Max << endl;
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
