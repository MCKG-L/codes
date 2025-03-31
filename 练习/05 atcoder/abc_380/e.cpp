#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353ll,inf = 1e18;
const int N = 5e5 + 10;
int pl[N],pr[N],ans[N],color[N];
int n;
int find1(int x){
    while(pl[x] != x) x = pl[x] = pl[pl[x]];
    return x;
}
int find2(int x){
    while(pr[x] != x) x = pr[x] = pr[pr[x]];
    return x;
}
void init(int n){
    for(int i=1;i<=n;i++) pl[i] = pr[i] = i,ans[i] = 1,color[i] = i;
}
void solve(){
    int q;cin >> n >> q;
    init(n);
    while(q --){
        int op;cin >> op;
        if(op == 1){
            int x,c;
            cin >> x >> c;
            int l = find1(x),r = find2(x);
            // cerr << l << ' ' << r << endl;
            ans[color[find1(x)]] -= r - l + 1;
            ans[c] += r - l + 1;
            color[l] = c;
            if(l - 1 >= 1 && color[find1(l-1)] == c){
                pl[l] = find1(l-1);
                pr[find2(l-1)] = r;
            }
            if(r + 1 <= n && color[find1(r+1)] == c){
                pl[find1(r+1)] = l;
                pr[r] = find2(r+1);
            }
        }else{
            int c;cin >> c;
            cout << ans[c] << endl;
        }
    }
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