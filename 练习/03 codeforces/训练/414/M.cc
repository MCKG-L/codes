#include <bits/stdc++.h>
#define elif else if
#define SZ(x) (int)x.size()
#define rep(i,a,n) for(int i = (a);i <= (n);i++)
#define dec(i,n,a) for(int i = (n);i >= (a);i--)
using namespace std;
using ll = long long;
using PII = pair<int,int>;
template<class T> void print(T x){cout << x << '\n';}
template<typename T> void print(vector<T> &a){for(int i = 0;i < a.size();i ++) cout << a[i] << " \n"[i + 1 == a.size()];}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail){cout << head << ' '; print(forward<Tail>(tail)...);}
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}
const int mod = 1e9 + 7;

void solve() { 
    int n, k; cin >> n >> k;
    if (n & 1) {
        vector<int> ans(n);
        int x = 1;
        for (int i = 0;i < n;i += 2) {
            ans[i] = x;
            ans[i + 1] = -x;
            x ++;
        }
        ans[n - 1] = k;
        print(ans);
    } else {
        vector<int> ans(n);
        int x = 1;
        for (int i = 0;i < n;i += 2) {
            ans[i] = x;
            ans[i + 1] = -x;
            x ++;
        }
        ans[0] += k;
        print(ans);
    }
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int T; cin>>T;
    while(T--)
        solve();
    return 0;
}