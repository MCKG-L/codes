#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
string s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >>t;
	while (t--) {
		vector<int>v1(1e4 + 1), v2(1e4 + 1), v3(1e4 + 1);
		cin >> s;
		int n = s.size();
		for (int i = 0; i <n; i++) {
			v1[i + 1] = v1[i] + (s[i] == 'X');
			v2[i + 1] = v2[i] + (s[i] == 'T');
			v3[i + 1] = v3[i] + (s[i] == 'U');
		}
		map<pii, int>mp;
		long long ans = 0;
		int d1 = 0; int d2 = 0;
		mp[{0, 0}] = 1;
		for (int i = 1; i <= n; i++) {
			d1 = v1[i] - v2[i]; d2 = v1[i] - v3[i];
			ans += mp[{d1, d2}];
		   mp[{d1, d2}]++;
		}
		cout << ans << "\n";
	}
	return 0;
}