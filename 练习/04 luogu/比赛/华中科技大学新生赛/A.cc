#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
int p;
int qmi(int a,int k){
    int ans = 1;
    while(k){
        if(k & 1) ans = ans * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return ans;
}
void solve(){
    int k,n;
    cin >> p >> k >> n;
    if(n == 1){
        cout << k << endl;
        return;
    }
    if(n == 2){
        cout << (k * k % p - 2 + p) % p << endl;
        return;
    }
    int ans = qmi(k,n-2) * ((k * k % p + p - 2)%p) % p;;
    int b = (k * (qmi(k,n-2) - 1 + p) % p) % p  * qmi(k-1,p-2) % p;
    ans = (ans + p - b) % p;
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}