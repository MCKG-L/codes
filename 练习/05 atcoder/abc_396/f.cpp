#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  2e5 + 10,inf = 3e18;
/*

*/
template <typename T>
struct Fenwick {
    int n;
    vector<T> w;
    Fenwick(int n) {
        this->n = n;
        w.resize(n + 1);
    }
    void add(int x, T k) {
        for (; x <= n; x += x & -x) {
            w[x] += k;
        }
    }
    void add(int x, int y, T k) { // 区间修改
        add(x, k), add(y + 1, -k);
    }
    T ask(int x) {  //单点查询
        auto ans = T();
        for (; x; x -= x & -x) {
            ans += w[x];
        }
        return ans;
    }
    T ask(int x, int y) { // 区间查询(区间和)
        return ask(y) - ask(x - 1);
    }
    int kth(T k) { //查找第k大的值
        int ans = 0;
        for (int i = __lg(n); i >= 0; i--) {
            int val = ans + (1 << i);
            if (val < n && w[val] < k) {
                k -= w[val];
                ans = val;
            }
        }
        return ans + 1;
    }
};
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(m + 1);
    vector<int> alls(n + 1);
    for(int i=0;i<n;i++){
        int x;cin >> x;
        alls[i] = x;
        a[x].push_back(i);
    }
    Fenwick<int> fenwick(m);
    int res = 0;
    for(int i=n-1;i>=0;i--){
        int x = alls[i] + 1;
        res += fenwick.ask(x - 1);
        fenwick.add(x,1);
    }
    vector<int> ans(m + 1,0);
    ans[0] = res;
    for(int c=1;c<m;c++){
        int c1 = 0,c2 = 0;
        for(int i=0;i<a[m-c].size();i++){
            c1 += a[m-c][i] - i; //增加量 a[m-c][i]前面有多少不为0的数,去除集合中为0的
            c2 += n - 1 - a[m-c][i] - (a[m-c].size() - i - 1);//减少量 a[m-c][i]后面有多少不为0的 
        }
        ans[c] = ans[c-1] + c1 - c2;
        // cerr << c1 << ' ' << c2  << endl;
    }
    for(int i=0;i<m;i++) cout << ans[i] << '\n';
    // cout << endl;/
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