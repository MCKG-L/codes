#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 2e5 + 10;
/*abc_405_f
将圆上的问题转化为链，可以知道，两个线段相交的条件是：1<=a<=c&&c<=b<=d或c<=a<=d&&d<=b<=2*n
是典型的二维数点问题，使用扫描线解决
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
    int val,x,id;
};
void solve(){
    int n,m;
    cin >> n >> m;
    n *= 2;
    vector<Node> q[n + 1];
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        q[u].push_back({0,v,0});   
    }
    int qq;cin >> qq;
    for(int i=1;i<=qq;i++){
        int c,d;
        cin >> c >> d;
        q[c].push_back({1,d,i});
        if(c - 1) q[c].push_back({-1,c-1,i});
        q[d].push_back({1,n,i});
        if(d - 1) q[d].push_back({-1,d-1,i});
        if(d - 1) q[c-1].push_back({1,d-1,i});
        if(c - 1) q[c-1].push_back({-1,n,i});
    }
    Fenwick fenwick(n);
    vector<int> ans(qq + 1);
    for(int i=1;i<=n;i++){
        for(auto [val,x,id] : q[i]){
            if(val == 0) fenwick.add(x,1);
            else{
                ans[id] += val * fenwick.ask(x);
            } 
        }
    }   
    for(int i=1;i<=qq;i++){
        cout << ans[i] << endl;
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