#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	int k;cin >> k;
	int na,nb,nc;
	for(int i=1;i<=k;i++){
		na = (b + c) / 2;
		nb = (a + c) / 2;
		nc = (a + b) / 2;
		a = na,b = nb,c = nc;
		if(na == nb && nb == nc){
			break;
		}
	}
	cout << a << ' ' << b << ' ' << c << endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	#ifdef LOCAL
		freopen("C:\\Users\\lanqiao\\text.in","r",stdin);
	#endif
	int T = 1;
	cin >> T;
	while(T --) solve();
	return 0;
}
