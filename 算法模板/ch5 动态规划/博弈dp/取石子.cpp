#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e5 + 10;
/*
N 个正整数组成的集合 A={a1​,a2​,…,aN​}。太郎君和次郎君将用以下游戏进行对决。
首先，准备一个有 K 个石子的堆。两人依次进行以下操作。太郎君先手。
从集合 A 中选择一个元素 x，从石堆中恰好移除 x 个石子。
不能进行操作的人输掉游戏。当两人都按照最优策略行动时，判断谁会获胜。
*/
void solve(){
	int n,k;cin >> n >> k;
	vector<int> a(n + 1);
	vector<int> dp(k + 1,0);
	for(int i=1;i<=n;i++) cin >> a[i];

	//如果一个状态可以转移到一个必败状态，则该状态是必胜状态 dp[0]是必败态
	for(int i=1;i<=k;i++){
		for(int j=1;a[j]<=i&&j<=n;j++){
			if(dp[i-a[j]] == 0){
				dp[i] = 1;break;
			}
		}
	}
	cout << (dp[k] ? "First" : "Second") << endl; 
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
	#ifdef LOCAL
		freopen("D:\\Others\\desktop\\text.in","r",stdin);
	#endif
    // cin >> T;
    while(T --) solve();
    return 0;
}