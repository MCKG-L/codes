#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;
template<typename T>
struct FenWick{
    int n;
    vector<T> tr;
    FenWick(int n): n(n),tr(n+1,0) {};
    int lowbit(int x){
        return x & -x;
    }
    void modify(int x,T c){
        for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
    }
    void modify(int l,int r,T c){
        modify(l,c);
        if(r + 1 <= n) modify(r+1,-c);
    }
    T query(int x){
        T ans = T();
        for(int i=x;i;i-=lowbit(i)) ans += tr[i];
        return ans;
    }
    T query(int l,int r){
        return query(r) - query(l-1);
    }
    int find_first(T sum){
        int ans = 0;
        T val = 0;
        for(int i=__lg(n);i>=0;i--){
            if((ans | (1 << i)) <= n && val + tr[ans | (1 << i)] < sum){
                ans |= 1 << i;
                val += tr[ans];
            }
        }
        return ans + 1;
    }
    int find_last(T sum){
        int ans = 0;
        T val = 0;
        for(int i=__lg(n);i>=0;i--){
            if((ans | (1 << i)) <= n && val + tr[ans | (1 << i)] <= sum){
                ans |= 1 << i;
                val += tr[ans];
            }
        }
        return ans;
    }
};

void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1);
    vector<int> g[n+1];
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> in(n+1),out(n+1);
    int k = 0;
    //求DFS序
    function<void(int,int)> dfs = [&](int u,int p) -> void {
        in[u] = ++ k;
        for(auto v : g[u]){
            if(v == p) continue;
            dfs(v,u);
        }
        out[u] = k;
    };
    dfs(1,-1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<array<int,2>> ans(q);
    vector<vector<array<int,3>>> query(n+1);
    for(int i=0;i<q;i++){
        int l,r,x;
        cin >> l >> r >> x;
        query[l-1].push_back({x,i,0});
        query[r].push_back({x,i,1});
    }
    FenWick<int> bit(n);
    for(int i=1;i<=n;i++){
        bit.modify(in[a[i]],1);
        for(auto [x,id,k] : query[i]){
            ans[id][k] = bit.query(in[x],out[x]);
        }
    }
    for(auto [l,r] : ans){
        if(l == r) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    cout << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}