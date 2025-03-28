#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10,mod = 998244353;
typedef pair<int,int> PII;
struct DSU{
    vector<int> f,siz;
    DSU(int n):f(n+1),siz(n+1,1){iota(f.begin(),f.end(),0);}
    int find(int x){
        while(f[x] != x) x = f[x] = f[f[x]];
        return x;
    }
    void add(int a,int b){
        a = find(a),b = find(b);
        if(a == b) return;
        f[b] = a;siz[a] += siz[b];
    }
    int size(int a){
        return siz[find(a)]; 
    }
};
void solve(){
    int n;cin >> n;
    DSU dsu(n);
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        dsu.add(i,x);
    }
    int ans = 1,cnt = 0;
    for(int i=1;i<=n;i++){
        if(dsu.size(i) & 1){
            cout << 0 << endl;
            return;
        }
        if(dsu.find(i) == i) cnt ++;
    }
    for(int i=0;i<cnt;i++) ans = ans * 2 % mod;
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