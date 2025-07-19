#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e4 + 10,mod = 998244353,inf = 1e18;
/*
给n个数，可重复的选取其中n个，问能否达到和为m
*/
bitset<N> operator*(bitset<N> &a,bitset<N> &b){
    bitset<N> c;
    for(int i=0;i<N;i++){
        if(b[i]) c |= a << i;
    }
    return c;
}
bitset<N> qmi(bitset<N> &a,int b){
    bitset<N> c;
    c[0] = 1;
    while(b){
        if(b & 0x1) c = c * a;
        b >>= 1;
        a = a * a;
    }
    return c;
}
void solve(){
    int n,m;
    cin >> n >> m;
    bitset<N> a;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        a[x] = 1;
    }
    a = qmi(a,n);
    cout << (a[m] ? "YES" : "NO") << endl;
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