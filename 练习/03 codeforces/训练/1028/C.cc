#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
int a[N],n,k;
map<int,int> mp;
int s;
void dfs(int u){
    if(u >= n){
        mp[s] ++;
        return;
    }
    dfs(u+1);
    //选
    int t = s;
    s = (s + a[u]) % k;
    dfs(u+1);
    s = t;
}
void solve(){
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    if(n > 17){
        cout << "YES" << endl;
        return;
    }
    dfs(0);
    for(auto [x,y] : mp){
        if(y >= 2){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}