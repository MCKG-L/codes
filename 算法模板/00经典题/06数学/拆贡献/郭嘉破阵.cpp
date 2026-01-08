#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 3e5 + 10,M = 32,mod = 1e9 + 7,inf = 1e18;
/*https://www.matiji.net/exam/brushquestion/57/4693/305EE97B0D5E361DE6A28CD18C929AF0
有两个数组a[1,n],b[1,n]
对于所有区间[i,j]，求f(i,j)之和，f(i,j)=(a[i]^a[i+1]^...^a[j]) * (b[i]+b[i+1]+...+b[j])
容易发现可以按照二进制位独立计算每一位
考虑异或前缀和
   0 1 1 0 1 1 0 1
-> 0 1 0 0 1 0 0 1
拆每一位的贡献：以当前位置i位区间右端点，在当前bit位产生的贡献
Xor[i,j] = Xor[1,j] ^ Xor[1,i-1]
若要Xor[i,j] == 1:则Xor[1,i-1] = Xor[1,j] ^ 1
即所有满足Xor[1,i-1] == Xor[1,j] ^ 1的位置i，对应区间[i+1,j]都满足Xor[i+1,j] == 1
由于Xor的前缀异或值只有0、1两种，所以容易维护cnt[xor]、sum[xor]
令now = Xor[1,j]，o = Xor[1,j] ^ 1
则当前位的贡献位：cnt[o] * b[1,j] - sum[o]
其中sum[o]表示前缀异或值位o的那些位置oi对应的b前缀和:sum[o] = sigma(oi)(sigma(1,oi)b[i])
*/
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1),b(n + 1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
        b[i] = (b[i] + b[i-1]) % mod;
    }
    int ans = 0;
    for(int bit=0;bit<=30;bit++){
        vector<int> cnt(2),sum(2);
        cnt[0] = 1;
        vector<int> Xor(n + 1);
        int s = 0;
        for(int i=1;i<=n;i++){
            Xor[i] = Xor[i-1] ^ (a[i] >> bit & 0x1);
        }
        for(int i=1;i<=n;i++){
            int now = Xor[i];
            int o = now ^ 1;
            s = (s + cnt[o]*b[i]%mod-sum[o] + mod) % mod;
            sum[now] = (sum[now] + b[i]) % mod;
            cnt[now] += 1;
        }
        ans = (ans + (1ll << bit) * s % mod) % mod;
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
