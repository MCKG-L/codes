#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
typedef pair<int,int> PII;
int h[N],ne[N],e[N],idx;
int match[N];
bool st[N];
int find(int x){
    for(int i=h[x];~i;i=ne[i]){
        int j = e[i];
        if(st[j]) continue;
        st[j] = 1;
        if(!match[j] || find(match[j])){
            match[j] = x;
            return true;
        }
    }
    return false;
}
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void solve(){
    vector<string> alls,a,b;
    int n,m,q;
    memset(h,-1,sizeof h);
    cin >> m >> n >> q;
    for(int i=0;i<q;i++){
        string u,v;cin >> u >> v;
        alls.push_back(u);alls.push_back(v);
        a.push_back(u);b.push_back(v);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    auto id = [&](string x) -> int {
        return lower_bound(alls.begin(),alls.end(),x)-alls.begin()+1;
    };
    map<int,int> ia,ib;
    for(int i=0;i<q;i++){
        int u = id(a[i]),v = id(b[i]);
        // cout << u << ' ' << v << endl;
        add(u,v);
        ia[u] ++;ib[v] ++;
    }
    int ans = 0;
    for(auto [x,y] : ia){
        memset(st,0,sizeof st);
        if(find(x)) ans ++;
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