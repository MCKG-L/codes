#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
int p[N],cnt;
bool st[N];
int phi[N];
void get_eulers(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]){
            p[cnt ++] = i;
            phi[i] = i - 1;
        }
        for(int j=0;p[j]*i<=n;j++){
            st[p[j]*i] = 1;
            if(i % p[j] == 0) phi[p[j]*i] = phi[i] * p[j];
            else phi[p[j]*i] = phi[i] * (p[j] - 1);
        }
    }
}
void solve(){
    int n;cin >> n;
    get_eulers(n);
    int ans = 0;
    for(int i=1;i<=n;i++) ans += phi[i];
    cout << ans << endl;
}
int main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}