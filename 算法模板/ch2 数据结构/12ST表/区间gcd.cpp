#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e5 + 10;
/* 题目来源：csp27-4
给出一个长度为n的序列，求其所有区间的价值，其中区间[l,r]的价值定义为l*r*gcd(a[l~r])
解法：首先需要一个可以O(1)查询区间gcd的数据结构，即ST表
在O(nlogn)预处理之后，可以是现在O(1)的时间复杂度内，求出任意区间的gcd值
考虑到区间gcd，如果右区间端点增加，则区间的gcd一定是不增的，即具有单调性
所以可以枚举区间的左端点，找到所有以该点作为左端点的区间gcd的值及其最右端点
gcd的减少是logn级别的，确定当前gcd值的最右区间可以使用二分找到

总时间复杂度是O(n(logn)^2)
该代码版本正确性待验证 思路正确
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
//查询所有区间的l*r*gcd
void solve(){
	int n;cin >> n;
	vector<int> a(n);
	for(auto &x : a) cin >> x;
	RMQ<int> rmq;
	rmq.work(a,[&](int a,int b){return __gcd(a,b);});
	int ans = 0;
	// O(nlogn^2)
	for(int i=1;i<=n;i++){
		int x = a[i-1];
		while(1){
			int l = i,r = n;
			while(l <= r){
				int mid = l + (r - l) / 2;
				if(rmq.ask(i,mid) >= x) l = mid + 1;
				else r = mid - 1;
            }
			// cerr << i << ' ' << r << ' ' << x << ' ';
			// cerr << i * x * (i + r) * (r - i + 1) / 2 << endl;
			ans = (ans + i * x % mod * (i + r) % mod * (r - i + 1) / 2 % mod) % mod;
			if(r + 1 <= n){
				x = rmq.ask(i,r+1);
			}else{
				break;
			}
		}
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