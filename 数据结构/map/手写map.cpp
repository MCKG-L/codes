#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
template <typename T, typename V,int N>
struct htb
{
    int h[N], to[N], idx = 0;
    int sz = 0;
    T k[N];
    V w[N];
    static int hashx(unsigned long long v)
    {
        v ^= v << 13;
        v ^= v >> 7;
        return (v ^ (v << 17)) % N;
    }
    bool count(T x)
    {
        for (int i = h[hashx(x)]; i; i = to[i])
        {
            if (k[i] == x)
                return true;
        }
        return false;
    }
    V &operator[](T x)
    {
        int &p = h[hashx(x)];
        for (int i = p; i; i = to[i])
        {
            if (k[i] == x)
                return w[i];
        }
        k[++idx] = x;
        to[idx] = p;
        w[p = idx] = 0;
        sz++;
        return w[idx];
    }
    bool erase(T x)
    {
        int prev = 0;
        for (int i = h[hashx(x)]; i; i = to[i])
        {
            if (k[i] == x)
            {
                if (prev == 0)
                    h[hashx(x)] = to[i];
                else
                    to[prev] = to[i];
                sz--;
                return true;
            }
            prev = i;
            i = to[i];
        }
        return false;
    }
    void clear()
    {
        while (idx)
            h[hashx(k[idx--])] = 0;
        sz = idx = 0;
    }
    int size() { return sz; }
};
htb<int,int,1000000> mp;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n + 1),dp(n + 1);
    dp[0] = 1;mp[0] = 1;
    int s1 = 0,s2 = 1;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        s1 += x;
        dp[i] = (s2 - mp[s1-m] + mod) % mod;
        s2 = (s2 + dp[i]) % mod;
        mp[s1] = (mp[s1] + dp[i]) % mod;
    }
    cout << (dp[n] + mod) % mod << endl;
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