#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
const int MOD = 1e9 + 7;
using ll = long long;
typedef pair<int,int> PII;
//状压DP
int n;
int g[4][4] = {
    {1,1,1,1},
    {0,0,1,1},
    {0,1,0,1},
    {1,0,0,0},
};
int f[N][4];
void solve(){
    cin >> n;
    f[1][0] = 1;
    for(int i=1;i<=n;i++){
        memset(f[i+1&1],0,sizeof f[0]);
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(g[j][k]) //能够转移
                f[i+1&1][k] = (f[i+1&1][k] + f[i&1][j]) % MOD;
            }
        }
    }
    cout << f[n+1&1][0] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}