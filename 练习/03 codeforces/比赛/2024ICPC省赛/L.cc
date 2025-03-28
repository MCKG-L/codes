#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
void solve(){
    int n;cin >> n;
    if(n < 4){
        cout << 4 - n << endl;
        return;
    }
    int ans = 0;
    while(__builtin_popcount(n) > 4) n += (n & -n),ans ++;
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}