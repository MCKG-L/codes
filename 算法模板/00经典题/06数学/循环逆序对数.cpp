#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  2e5 + 10,inf = 3e18;
/* 题目来源 abc_396_f
给定一个数组A(0 <= A[i] < m)，对于k=0,1,2,3,...m-1，进行如下操作得到数组B：
B[i] = (A[i] + k) % m ,i=0,1,2,3,...n-1 求B数组的逆序对数

为了体现每一个元素改变时对总逆序对数的影响，将0~m-1的每个值对应的位置坐标存储起来，记作g[i]
考虑k = c和k = c - 1的一般情况，发现只有当Bk[i]变为0时，逆序对的数目才发生变化，考虑增加量c1和减少量c2
Bk[i] == 0,对于原数组A来说即A[i] = m - k,这些位置存储在g[m-k]中
对于g[m-k]的每个值(在原数组中的位置),该位置前面不为0的数，会使得逆序对数增加 注意去除g[m-c]中本身位置的重复计算
该位置后面不为0的数，会使得逆序对数减少 也应去除重复计算的部分
for idx=0-siz(g[m-c])-1
c1 = g[m-c][idx] - idx
c2 = n - 1 -  g[m-c][idx] - (g[m-c].size() - i - 1)
*/
//jiangly-Fenwick模板 [1-n]
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