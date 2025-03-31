#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353ll,inf = 1e18;
void solve(){
    string s;cin >> s;
    int n = s.size();
    int k;cin >> k;
    s = ' ' + s;
    auto dfs = [&](auto dfs,int x,bool f)->char{
        if(x <= n){
            if(f){
                int off = isupper(s[x]) ? 32 : -32;
                return s[x] + off;
            }else return s[x];
        }
        int k = n;
        while(k * 2 < x){
            k *= 2;
        }
        return dfs(dfs,x - k,f ^ 1);
    };
    while(k --){
        int x;cin >> x;
        cout << dfs(dfs,x,0) << ' ';
    }
    cout << endl;
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