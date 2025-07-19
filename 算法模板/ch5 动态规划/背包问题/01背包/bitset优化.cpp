#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 4e6 + 10,mod = 998244353,inf = 1e18;
/*
5
1 2 3 4 5
*/
void solve(){
    int n;cin >> n;
    bitset<N> s;
    //s第i位表示i能否取到
    s.set(0,1);
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        s |= s << x;
    }
    cout << s[6] << endl;
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