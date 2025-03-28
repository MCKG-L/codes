#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
// #define int long long
const int N = 2e5 + 10;
typedef pair<int,int> PII;
using ll = long long;
int p[N],n,m;
int find(int x){
    while(p[x] != x) x = p[x] = p[p[x]];
    return x;
}
void ini(){
    for(int i=1;i<=n;i++) p[i] = i;
}
void solve(){
    cin >> n >> m;
    ini();
    vector<int> adj(m + 10);
    vector<int> mp[n + 10]; 
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        int t = min(a,b);
        a = find(a),b = find(b);
        if(a == b){
            adj[i] = t;
            mp[a].push_back(i);
        }
        else{
            p[b] = a;
            mp[a].insert(mp[a].end(),mp[b].begin(),mp[b].end());
            mp[b].clear();
        }
    }
    vector<PII> pos;
    for(int i=1;i<=n;i++){
        if(find(i) == i){
            pos.push_back({mp[i].size(),i});
        }
    }
    int cnt = pos.size();
    if(cnt == 1){
        cout << 0 << endl;
        return ;
    }
    cout << cnt - 1 << endl;
    sort(pos.begin(),pos.end(),greater<PII>());
    int idx = 0;
    for(auto [_,root] : pos){
        for(auto v : mp[root]){
            cout << v << ' ' << adj[v] << ' ' << pos[++idx].second << endl;
            if(idx >= cnt - 1) return;
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