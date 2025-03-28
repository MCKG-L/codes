#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
int qmi(int a,int k){
    int ans = 1LL;
    while(k){
        if(k & 1) ans = 1LL * ans * a % mod;
        k >>= 1;
        a = 1LL * a * a % mod;
    }
    return ans;
}
void solve(){
    int n;cin >> n;
    priority_queue<int,vector<int>,greater<int>> heap;
    int ans = 1;
    unordered_map<int,int> mp;
    int Max = -1;
    bool ok = 1;
    for(int i=0;i<n*2;i++){
        int x;cin >> x;
        if(x == -1 && ok){
            int k = heap.top();
            if(k < Max){
                ok = 0;
                ans = 0;
                continue;
            }
            ans = (ans * mp[k] % mod) * qmi(heap.size(),mod-2) % mod;
            heap.pop();
            mp[k] --;
            Max = max(Max,k);
        }else{
            heap.push(x);
            mp[x] ++;
        }
    }
    cout << ans << endl;
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