#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 2e5 + 10;
/* abc401_d
给定n和k，和一个长度为n且由'.'、'o'、'?'组成的字符串
可以将其中的'?'替换成'.'或'o'使得替换之后的字符串满足：恰好有k个'o'且任意两个'o'
都不相邻
对于得到的所有可能的情况，如果字符串的当前位置可以是'.'或'o'则输出'?'，否则输出其唯一取值
即得到的满足上述条件的所有字符串，构成一个集合X
输出一个长度为n的字符串：
对于i[1-n],如果X中所有字符串的第i为都为'.'则输出'.'，都为'o'则输出'o'
否则输出'?'
*/
void solve(){
	int n,k;
	cin >> n >> k;
	string s;cin >> s;
	if(k == 0){
		cout << s << endl;
		return;
	}
	s = ' ' + s + ' ';
	for(int i=1;i<=n;i++){
		if(s[i] == 'o') s[i-1] = s[i+1] = '.';
	}
	int cnt = 0;
	for(int i=1;i<=n;i++) cnt += s[i] == 'o';
	if(cnt == k){
		for(int i=1;i<=n;i++) s[i] = s[i] == '?' ? '.' : s[i];
		cout << s.substr(1,n) << endl;
		return;
	}
	string ans;
	for(int i=1;i<=n;i++){
		if(s[i] == '?'){
			int j = i;
			while(j <= n && s[j] == '?'){
				j ++;
			}
			cnt += (j - i + 1) / 2;
			if((j - i) & 0x1){
				for(int c=0;c<j-i;c++) ans += (c & 0x1) ? '.' : 'o';
			}else{
				ans += s.substr(i,j-i);
			}
			i = j - 1;
		}else{
			ans += s[i];
		}
	}
	if(cnt == k){
		cout << ans << endl;
	}else{
		cout << s.substr(1,n) << endl;
	}
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