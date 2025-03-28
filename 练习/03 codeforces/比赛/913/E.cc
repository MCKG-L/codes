#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;cin >> n;
    ll ans = 1;
    while(n){
        int x = n % 10;
        n /= 10;
        int cnt = 0;
        for(int i=0;i<=x;i++){
            for(int j=0;j<=x;j++){
                int d = x - i - j;
                if(d >= 0) cnt ++;
            }
        }
        ans *= cnt;
    }
    cout << ans << endl;
}
int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}