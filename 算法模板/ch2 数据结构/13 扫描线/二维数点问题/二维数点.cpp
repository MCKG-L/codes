#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 2e5 + 10;
/* 洛谷P10814
给你一个长为 n 的序列 a，有 m 次询问，每次询问给定 l,r,x，求 [l,r] 区间中小于等于 x 的元素个数。
1≤n,m,ai​,l,r,x≤2×106
*/
struct Node{
    int val,x,id;
};
struct Fenwick{
    vector<int> tr;
    int n;
    Fenwick(int n){
        this->n = n;
        tr.assign(n + 10,0);
    }
    void add(int x,int c){
        for(;x<=n;x+=x&-x) tr[x] += c;
    }
    int ask(int x){
        int res = 0;
        for(;x;x-=x&-x) res += tr[x];
        return res;
    }
};
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    int Max = *max_element(a.begin(),a.end());
    vector<Node> q[n+1];
    for(int i=0;i<m;i++){
        int l,r,x;
        cin >> l >> r >> x;
        q[l-1].push_back({-1,x,i});
        q[r].push_back({1,x,i});
        Max = max(Max,x);
    } 
    Fenwick fenwick(Max);
    vector<int> ans(m);
    for(int i=1;i<=n;i++){
        fenwick.add(a[i],1);
        for(auto [val,x,id] : q[i]){
            ans[id] += val * fenwick.ask(x);
        }
    }
    for(auto x : ans) cout << x << endl;
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