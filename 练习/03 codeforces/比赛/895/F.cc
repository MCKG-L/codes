#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
void solve(){
    int n;cin >> n;
    vector<int> a(n+1),ind(n+1),c(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ind[a[i]] ++;
    }
    for(int i=1;i<=n;i++) cin >> c[i];
    vector<bool> st(n+1);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(ind[i] == 0) q.push(i),st[i] = 1;
    }
    vector<int> ans;
    //拓扑
    while(q.size()){
        int u = q.front();q.pop();
        ans.push_back(u);
        ind[a[u]] --;
        if(ind[a[u]] == 0) q.push(a[u]),st[a[u]] = 1;
    }
    //只剩下环上的点没有处理
    for(int i=1;i<=n;i++){
        if(st[i]) continue;
        int u = a[i];st[i] = 1;
        int it = i,mn = c[i];
        while(u != i){
            st[u] = 1;
            if(c[u] < mn){
                mn = c[u];
                it = u;
            }
            u = a[u];
        }
        u = a[it];
        // cout << "--" << it << endl;
        while(it != u){
            ans.push_back(u);
            u = a[u];
        }
        ans.push_back(it);
    }
    for(auto i : ans) cout << i << ' ';
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}