#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 5e3 + 10,M = 1e5 + 10;
/*
汉诺塔问题：将所有圆盘从A柱移动到C柱
问第k次操作后，编号(从小到大)为i的圆盘所在的柱子
k以二进制的形式给出
3
011
-->BBA
5
11111
-->CCCCC
*/
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    int siz = s.size();
    auto dfs = [&](auto dfs,int n,char a,char b,char c)->void{
        if(n < 0) return;
        if(s[siz-n-1] == '1'){
            dfs(dfs,n-1,b,a,c);
            cout << c;
        }else{
            dfs(dfs,n-1,a,c,b);
            cout << a;
        }
    };
    dfs(dfs,n-1,'A','B','C');
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
