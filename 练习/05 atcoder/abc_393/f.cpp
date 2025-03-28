#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1e6 + 10,inf = 1e18;
void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> s(n+1),a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<array<int,3>> query(q);
    for(int i=0;i<q;i++){
        int u,v;
        cin >> u >> v;
        query[i] = {u,v,i};
    }
    s[0] = -inf;
    int len = 0,idx = 0;
    sort(query.begin(),query.end());
    vector<int> ans(q);
    for(int i=1;i<=n;i++){
        int l = 0,r = len;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(s[mid] < a[i]) l = mid + 1;
            else r = mid - 1;
        }
        // 2 5 6 5 2 1 7 9 7 2
        len = max(len,r+1);
        s[r+1] = a[i];
        // cerr << "len: " << len << endl;
        while(idx < q && query[idx][0] == i){
            int x = query[idx][1],id = query[idx][2];
            int l = 0,r = len;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(s[mid] <= x) l = mid + 1;
                else r = mid - 1;
            }
            // cerr << i << ' ' << x << ' ' << r << endl;
            ans[id] = r;
            idx ++;
        }
    }
    for(auto x : ans) cout << x << '\n';
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