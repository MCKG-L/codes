#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 1e5 + 10;
/* 洛谷 P5490
给出n个矩形，求这n个矩形的面积并
注意线段树[l,r]节点存储的是[1,r+1]之间的线段长度
*/
struct Node{
    int l,r;
    int cnt,len;
}tr[N<<4];
vector<int> alls;
void pushup(int u){
    // tr[u].l = tr[u<<1].l,tr[u].r = tr[u<<1|1].r;
    if(tr[u].cnt) tr[u].len = alls[tr[u].r] - alls[tr[u].l-1];
    else tr[u].len = tr[u<<1].len + tr[u<<1|1].len;
}
void modify(int u,int st,int ed,int l,int r,int val){
    if(l > ed || r < st) return;
    if(l <= st && r >= ed){
        tr[u].cnt += val;
    }else{
        int mid = (st + ed) / 2;
        if(l <= mid) modify(u<<1,st,mid,l,r,val);
        if(r > mid) modify(u<<1|1,mid+1,ed,l,r,val);
    }
    pushup(u);
}
void build(int u,int l,int r){
    tr[u] = {l,r,0,0};
    if(l == r) return;
    int mid = (l + r) / 2;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    // pushup(u);
}
struct Line{
    int x1,x2,y,val;
};
void solve(){
    int n;cin >> n;
    vector<Line> line;
    for(int i=1;i<=n;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        alls.push_back(x1);alls.push_back(x2);
        line.push_back({x1,x2,y1,1});
        line.push_back({x1,x2,y2,-1});
    }
    sort(alls.begin(),alls.end());
    int tot = alls.erase(unique(alls.begin(),alls.end()),alls.end())-alls.begin();
    auto find = [&](int x){
        return lower_bound(alls.begin(),alls.end(),x)-alls.begin() + 1;
    };
    sort(line.begin(),line.end(),[&](Line p1,Line p2){
        return p1.y < p2.y;
    });
    build(1,1,tot-1);
    int ans = 0;
    // cerr << tot << endl;
    for(int i=0;i<line.size()-1;i++){
        auto [x1,x2,y,val] = line[i];
        int l = find(x1),r = find(x2);
        // cerr << l << ' ' << r << endl;
        modify(1,1,tot-1,l,r-1,val);
        ans += tr[1].len * (line[i+1].y - y);
    }
    cout << ans << endl;
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