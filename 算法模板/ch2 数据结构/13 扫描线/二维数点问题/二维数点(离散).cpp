#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 2e5 + 10;
/* 洛谷P2163
平面内有许多离散的点，有m次询问，每次询问指定矩形范围内的点的个数
离散化+离线+扫描线
使用差分思想，用树状数组维护(0,0)->(x,y)的点数
*/
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
struct Node{
    int x,y,val,id;
};
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> alls;
    vector<Node> q;
    for(int i=1;i<=n;i++){
        int x,y;
        cin >> x >> y;
        alls.push_back(y);
        q.push_back({x,y,0,0});
    }
    for(int i=1;i<=m;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        alls.push_back(y2);
        alls.push_back(y1-1);
        q.push_back({x2,y2,1,i});
        q.push_back({x1-1,y1-1,1,i});
        q.push_back({x2,y1-1,2,i});
        q.push_back({x1-1,y2,2,i});
    }
    sort(alls.begin(),alls.end());
    int tot =  alls.erase(unique(alls.begin(),alls.end()),alls.end()) - alls.begin();
    Fenwick fenwick(tot);
    sort(q.begin(),q.end(),[&](Node p1,Node p2){
        if(p1.x != p2.x) return p1.x < p2.x;
        return p1.val < p2.val;
    });
    auto find = [&](int x)->int{
        return lower_bound(alls.begin(),alls.end(),x)-alls.begin() + 1;
    };
    vector<int> ans(m + 1);
    for(auto [x,y,val,id] : q){
        y = find(y);
        if(val == 0){
            fenwick.add(y,1);
        }else{
            if(val == 1) ans[id] += fenwick.ask(y);
            else ans[id] -= fenwick.ask(y);
        }
    }
    for(int i=1;i<=m;i++) cout << ans[i] << endl;
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