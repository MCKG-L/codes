#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 4e6 + 10,mod = 1e9 + 7,inf = 1e18;
/*abc_384_f
定义 f(x)=x/lowbit(x)
现给定一个长度为 n 的序列 a，求所有数对的f(a[i]+a[j])之和

设g[i]表示所有能被2^i整除的数对之和 则g[i]-g[i+1]表示恰好能被2^i整除的数对之和
则2^i对答案的贡献为(g[i]-g[i+1])/2^i

下面考虑求给g[i]：(a[i]+a[j]) % x == 0 --> (a[i]%x + a[j]%x)%x == 0
使用桶记录前面能被x整除的数对之和以及个数，则当前a[j]造成的贡献为：sum[(x-a[j]%x)%x] + a[j]*cnt[(x-a[j]%x)%x]
注意每次清空
*/
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> g(30);//能被1<<i整除的数对和
    unordered_map<int,int> sum,cnt;
    int ans = 0;
    for(int i=0;i<=25;i++){
        int x = 1ll << i;
        for(int j=1;j<=n;j++){
            cnt[a[j] % x] ++;
            sum[a[j] % x] += a[j];
            g[i] += sum[(x-a[j]%x)%x] + a[j]*cnt[(x-a[j]%x)%x];
        }
        for(int j=1;j<=n;j++){
            cnt[a[j] % x] --;
            sum[a[j] % x] -= a[j];
        }
    }
    for(int i=0;i<=25;i++){
        ans += (g[i] - g[i+1]) /  (1ll << i);
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