#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353ll,inf = 1e9;
const int N = 2e5 + 10;
/* 使用ST表解决RMQ问题 区间最值问题 支持允许重复贡献的区间最值问题
预处理O(nlogn)、查询O(1) 可以求区间最大值、最小值、gcd、lcm、按位与、按位或
*/
template<class T>
struct RMQ { //传入数组[0~n-1] 查询下表[1~n]
	int n;
	vector<T>a;
	vector<array<T, 21>> f;
	function<T(T, T)> func;
	RMQ() {};
	vector<int> len;
	void work(vector<T> a,function<T(T, T)> func_) { //传入lmbda表达式
		this->a = a;
		this->func = func_;
		n = a.size();
		f.assign(n+1, {});
		len.resize(n + 1);
		len[1] = 0;
		for (int i = 2; i <= n; i++) len[i] = len[i / 2] + 1;//求log2(i)
		for (int i = 1; i <= n; i++) f[i][0] = a[i-1];
		const int lg = log2(n);
		for (int j = 1; j <= lg; j++) {
			for (int i = 1; i + (1 << (j)) - 1 <= n; i++) {
				f[i][j] = func(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
			}
		}
		return;
	}
	T ask(int l, int r) {
		return func(f[l][len[r - l + 1]], f[r - (1 << len[r - l + 1]) + 1][len[r - l + 1]]);
	}
};
void solve(){
    int n,m;cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    RMQ<int> rmq;
    rmq.work(a,[&](int a,int b){return __gcd(a,b);});
    while(m --){
        int l,r;
        cin >> l >> r;
        cout << rmq.ask(l,r) << endl;
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