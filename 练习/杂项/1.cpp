#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1e6 + 10;
int prime[N],cnt,p[N];
bool st[N];
vector<int> ans;
void solve(){
	int a;cin >> a;
	int x = sqrt(a);
	if((x + 1)*(x + 1) <= a) x ++;
	int l = 0,r = ans.size() - 1;
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(ans[mid] <= x) l = mid + 1;
		else r = mid - 1;
	}
	cout << ans[r] * ans[r] << endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T = 1;
	for(int i=2;i<=1e6;i++){
		if(!st[i]) prime[cnt++] = i,p[i] = i;
		for(int j=0;prime[j]<=1e6/i;j++){
			st[i*prime[j]] = 1;
			p[i*prime[j]] = prime[j];
			if(i % prime[j] == 0) break;
		}
	}
	for(int i=1;i<=1e6;i++){
		int nums = 0,x = i;
		while(p[x]){
			nums ++;
			int t = p[x];
			while(x % t == 0){
				x /= t;
			}
		}
		if(nums == 2) ans.push_back(i);
	}
	#ifdef LOCAL
		freopen("D:\\Others\\desktop\\text.in","r",stdin);
	#endif
	cin >> T;
	while(T --) solve();
	return 0;
}