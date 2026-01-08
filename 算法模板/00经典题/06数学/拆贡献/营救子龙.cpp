#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1100000,M = 5010;
/*https://www.matiji.net/exam/brushquestion/61/4693/305EE97B0D5E361DE6A28CD18C929AF0
初始有一个数组a[1,n]，可以进行m次操作，每次可以选择一个位置i，使得a[i] + 1
问：所有n^m种操作方案下，产生的sigma(1,n)f(a[i])之和，其中f(x)表示x的二进制中1
的个数
每一种方案都会产生一个sigma(1,n)f(a[i])
拆贡献：
对于a[i]的操作次数可以为0~m，并且发现所有的a[i]都是独立计算的
m=0:f(a[i]+0)*(n-1)^m
m=1:f(a[i]+1)*(n-1)^m-1
...
m=m:f(a[i]+m)*(n-1)^0
-->sigma(1,m)f(a[x]+i)*(n-1)^m-i
*/
int C[M][M];
void solve(){
    int n,m;
    cin >> n >> m;
    C[0][0] = 1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=m;j++){
            if(j == 0) C[i][j] = 1;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
    //(n-1)^(m-i)
    vector<int> w(m + 10);
    w[m] = 1;
    for(int i=m-1;i>=0;i--){
        w[i] = w[i+1] * (n - 1) % mod;
    }
    vector<int> f(N);
    auto cal = [&](int x)->int{
        int res = 0;
        for(int i=0;i<=30;i++){
            res += (x >> i & 0x1);
        }
        return res;
    };
    for(int i=0;i<N;i++){
        f[i] = cal(i);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        for(int j=0;j<=m;j++){
            ans = (ans + f[x+j] * C[m][j] % mod * w[j] % mod) % mod;
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
