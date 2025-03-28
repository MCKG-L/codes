#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 1e6 + 10;
int p[N],vis[N],cnt[N],ins[N];
int n,m;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void unite(int a,int b){
    a = find(a),b = find(b);
    if(a != b) p[a] = b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i] = i;
    while(m--){
        int u,v;
        cin >> u >> v;
        vis[u] ++,vis[v] ++;
        unite(u,v);
    }
    for(int i=1;i<=n;i++){
        cnt[find(i)] ++;
        ins[find(i)] += vis[i];
    }
    vector<int> v;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x = find(i);
        if(x != i) continue;
        v.push_back(cnt[x]);
        ans += (cnt[x] * (cnt[x] - 1) - ins[x]) / 2;
    }
    sort(v.begin(),v.end());
    if(ans == 0) ans += v[0] * v[1];
    cout << ans << endl;
    return 0;
}