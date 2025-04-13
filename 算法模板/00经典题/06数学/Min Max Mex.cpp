#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 2e5 + 10;
/* codeforces DIV3_1016_E
给你一个长度为 n 的数组 a 和一个数字 k子数组的定义是数组中
一个或多个连续元素的序列。你需要将数组a分割成k个不重叠的子数组 b1,b2,…,bk,
使得这k个子数组的Mex值的最小值最大，求最大值

二分 check思路
*/
void solve(){
	int n,k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for(int i=1;i<=n;i++) cin >> a[i];
	int l = 0,r = *max_element(a.begin()+1,a.begin()+1+n) + 3;
	auto check = [&](int x)->int{
		int cnt = 0,cur = 0;
		vector<int> mp(n + 2);
		for(int i=1;i<=n;i++){
			if(a[i] <= n && a[i] <= x){
				mp[a[i]] = 1;
			}
			while(mp[cur]){
				cur ++;
			}
			if(cur >= x){
				cnt ++;
				for(int j=0;j<=min(x+1,n);j++) mp[j] = 0;
				cur = 0;
			}
		}
		return cnt;
	};
	while(l <= r){
		int mid = l + (r - l) / 2;
		int t = check(mid);
		if(check(mid) >= k) l = mid + 1;
		else r = mid - 1;
	}
	cout << r << endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T = 1;
	#ifdef LOCAL
		freopen("D:\\Others\\desktop\\text.in","r",stdin);
	#endif
	cin >> T;
	while(T --) solve();
	return 0;
}