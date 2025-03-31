#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353ll,inf = 1e9;
const int N = 2e5 + 10;
void solve(){
    int n,m;
    cin >> n >> m;
    auto Josephus = [&](auto &Josephus,int n,int m)->int{
        if(n == 1) return 0;
        return (Josephus(Josephus,n-1,m)+m)%n;
    };
    cout << Josephus(Josephus,n,m) + 1 << endl;
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