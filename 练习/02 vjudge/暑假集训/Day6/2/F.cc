#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e5 + 10,mod = 998244353;
bool st[N];
int cnt[N];
int n;
char s[N];
vector<int> p;
int main()
{
    cin >> n >> s + 1;
    for(int i=1;i<n;i++) if(n % i == 0) p.push_back(i);
    int ans = 0;
    for(auto v : p){
        for(int i=1;i<=v;i++) st[i] = 0;
        for(int i=1;i<=n;i++){
            int k = i % v;
            if(k == 0) k = v;
            if(s[i] == '.') st[k] = 1;
        }
        cnt[v] = 1;
        for(int i=1;i<=v;i++){
            if(st[i] == 0) cnt[v] = (cnt[v] * 2) % mod;
        }
        for(auto vv : p){
            if(vv >= v) break;
            if(v % vv == 0) cnt[v] = (cnt[v] - cnt[vv] + mod) % mod;
        }
        ans = (ans + cnt[v]) % mod;
    }
    cout << ans << endl;
    return 0;
}