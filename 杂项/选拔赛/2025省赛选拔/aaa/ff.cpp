#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
const int N = 2e5 + 10,mod = 1e9 + 7,inf = 1e18;
void solve(){
    int n;cin >> n;
    int res = 0;
    vector<int> a(n + 1);
    vector<int >alls;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        alls.push_back(a[i]);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    auto find = [&](int x)->int{
        return lower_bound(alls.begin(),alls.end(),x)-alls.begin() + 1;
    };
    vector<int> dp(n + 1,-1);
    vector<int> primes(1010);
    vector<bool> st(1010);
    int cnt = 0;
    for(int i=2;i<=1000;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]<=1000/i;j++){
            st[primes[j]*i] = 1;
            if(i % primes[j] == 0) break;
        }
    }
    // for(int i=1;i<=100;i++) cout << st[i] << ' ';
    
    auto cal = [&](int x)->int{
        int idx = find(x);
        if(~dp[idx]) return dp[idx];
        if(x == 1 || x == 2){
            dp[idx] = 0;
            return 0;
        }
        int sum = 0,k = 0;
        int cnt = 0;
        int t = x;
        for(int i=2;i<=x/i;i++){
            if(x % i == 0){
                sum ++;
                if(sum >= 2) {
                    k = 3;
                    break;
                }
                while(x % i == 0){
                    x /= i;
                    cnt ++;
                }
            }
            k = cnt;
        }
        if(x > 1){
            k = 3;
        }
        int ans = st[k+1] ? 0 : t;
        dp[idx] = ans;  
        return ans;
    };
    res = 0;
    for(int i=1;i<=n;i++){
        int x = a[i];
        res += cal(x);
    }
    cout << res << endl;
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