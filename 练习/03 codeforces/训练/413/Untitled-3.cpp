#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
    {
        int x; cin >> x;
        int v = 0;
        while(x --)
        {
            int t; cin >> t;
            v |= (1ll << (t - 1));
        }
        vec[i] = v;
    }
    map<int, int> mp;
    int l = n / 2, r = n / 2 + n % 2;
    for(int i=0;i<(1ll<<l);++i)
    {
        int x = i;
        int v = 0;
        bool flag = true;
        for(int j=0;j<l;j++)
        {
            if(x & (1ll << j))
            {
                if(v & vec[j])
                {
                    flag = false;
                    break;
                }
                v |= vec[j];
            }
        }
        if(flag) mp[v] ++;
    }
    int ans = 0;
    // int ans = mp[(1<<p) - 1];
    for(int i=0;i<(1ll<<r); ++i)
    {
        int x = (i << l);
        int v = 0;
        bool flag = true;
        for(int j=l;j<n;j++)
        {
            if(x & (1ll << j))
            {
                if(v & vec[j])
                {
                    flag = false;
                    break;
                }
                v |= vec[j];
            }
        }
        if(flag)
        {
            ans += mp[(1ll << p) - v - 1];
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}