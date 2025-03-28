#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
void solve(){
    int n,k;
    cin >> n >> k;
    string s;cin >> s;s = ' ' + s;
    set<pair<int,int>> st;
    vector<int> pre(n+2);
    vector<int> l(k+1),r(k+1);
    for(int i=1;i<=k;i++){
    	int x;cin >> x;
    	l[i] = x;
	}
	for(int i=1;i<=k;i++){
		int x;cin >> x;
		r[i] = x;st.insert({x,i});
	}
    int q;cin >> q;
    for(int i=0;i<q;i++){
        int x;cin >> x;
        int p = (*st.lower_bound({x,0})).second;
//        cout << "p: " << p << endl;
        int L = l[p],R = r[p];
        int m = min(L+R-x,x);
        int M = max(L+R-x,x);
        pre[m] ++,pre[M+1]--;
    }
    for(int i=1;i<=n;i++) pre[i] += pre[i-1];
    string ans = s;
    for(int i=1;i<=n;i++){
        if(pre[i] % 2 == 0) continue;
        auto p = (*st.lower_bound({i,0})).second;
        int x = l[p] + r[p];
        ans[i] = s[x-i];
    }
    for(auto i : ans){
    	if(i != ' ') cout << i;
	}
	cout << endl;
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}