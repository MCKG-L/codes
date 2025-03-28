#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
int mod;
//f(n) = f(n-1)*k - f(n-2) 矩阵快速幂
struct Node{
    int a[2][2];
};
Node mul(Node a,Node b){
    Node ans = {0,0,0,0};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                ans.a[i][j] = ((ans.a[i][j] + a.a[i][k] * b.a[k][j] % mod) % mod + mod) % mod;
            }
        }
    }
    return ans;
}
Node qmi(Node a,int k){
    Node ans = {1,0,0,1};//单位矩阵
    while(k){
        if(k & 1) ans = mul(ans,a);
        k >>= 1;
        a = mul(a,a);
    }
    return ans;
}
void solve(){
    int m,k,n;
    cin >> m >> k >> n;
    mod = m;
    if(n == 1){
        cout << k << endl;
        return;
    }
    if(n == 0){
        cout << 2 << endl;
        return;
    }
    Node a = {k,-1,1,0};
    Node b = qmi(a,n-2);
    int p1 = (k * k % mod - 2 + mod) % mod,p2 = k;
    int ans = (b.a[0][0] * p1 % mod + b.a[0][1] * p2 % mod + mod) % mod;
    cout << ans << endl;
}
signed main()
{
    IOS;
	int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}