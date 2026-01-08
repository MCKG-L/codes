#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 1e5 + 10,M = 32,mod = 1e9 + 7,inf = 1e18;
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> primes;
    int m = 100;
    vector<bool> st(m + 1);
    //1<=ai<=100
    for(int i=2;i<=m;i++){
        if(!st[i]) primes.push_back(i);
        for(int j=0;primes[j]<=m/i;j++){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) break;
        }
    }
    vector<array<int,30>> f(n + 1);
    int len = primes.size();
    // cerr << len << endl;//最多25个质因子
    //预处理每个数的质因子个数（奇偶）
    for(int i=1;i<=n;i++){
        int x = a[i];
        for(int j=0;j<len;j++){
            while(x && x % primes[j] == 0){
                x /= primes[j];
                f[i][j] ^= 1;
            }
        }
    }
    int ans = 0;
    unordered_map<int,int> mp;
    //分治 统计答案
    auto dfs = [&](auto dfs,int l,int r)->void{
        if(l == r){
            for(int j=0;j<len;j++){
                if(f[l][j]) return;
            }
            ans = 1;
            return;
        }
        int mid = (l + r) / 2;
        dfs(dfs,l,mid),dfs(dfs,mid+1,r);
        mp.clear();
        int x = 0;//状态压缩表示当前的质因子奇偶情况
        for(int i=mid;i>=1;i--){
            for(int j=0;j<len;j++){
                if(!f[i][j]) continue;
                x ^= (1ll << j);
            }
            mp[x] = i;
        }
        x = 0;
        for(int i=mid+1;i<=n;i++){
            for(int j=0;j<len;j++){
                if(!f[i][j]) continue;
                x ^= (1ll << j);
            }
            if(mp.count(x)){
                ans = max(ans,i-mp[x]+1);
            }
        }
    };
    dfs(dfs,1,n);
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
