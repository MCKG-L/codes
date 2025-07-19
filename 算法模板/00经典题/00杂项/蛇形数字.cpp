#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 5e5 + 10,mod = 1e9 + 7,inf = 1e18;
/* abc_387_c
在 10 以上（含）的正整数中，我们称一个数字为蛇数当且仅当其开头的位（首位）数字严格大于其他位数。例如， 31 和 201 是蛇数，而 35 和 202 不是。
求 L 以上 R 以下的蛇数的个数
*/
int qmi(int a,int b){
	int res = 1;
	while(b){
		if(b & 0x1) res = res * a;
		b >>= 1;
		a = a * a;
	}
	return res;
}
void solve(){
    int l,r;
    cin >> l >> r;
    auto Pow = [&](int x,int t)->int{
        int ans = 0;
        for(int i=1;i<=x;i++){
            // ans += pow(i,t-1);//被精度害死的！！！
			ans += qmi(i,t-1);
        }
        return ans;
    };
    auto dfs = [&](auto dfs,string x,int n,int M,int u,bool ok)->int{
        if(u >= n){
            return 1;
        }
        if(ok){ //[0,M]
            return (M+1) * dfs(dfs,x,n,M,u+1,1);
        }else{
            int ans = 0,m = x[u]-'0';
            int Max = min(M,m);
            if(Max == m){
                ans += dfs(dfs,x,n,M,u+1,0) + (Max > 0 ? Max * dfs(dfs,x,n,M,u+1,1) : 0);
            }else{
                ans += (Max + 1) * dfs(dfs,x,n,M,u+1,1);
            }
            return ans;
        }
    };
    auto cal = [&](string x)->int{
        int ans = 0,n = x.size();
        for(int i=1;i<=n-1;i++) ans += Pow(9,i);
        int M = x[0] - '0';
        ans += Pow(M-1,n);
        return ans + dfs(dfs,x,n,M-1,1,0);
    };
    cout << cal(to_string(r)) - cal(to_string(l-1)) << endl;
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