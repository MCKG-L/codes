#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

void solve(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    if(a[1] % a[0] || a[2] % a[0]){
        cout << "NO" << endl;
        return;
    }
    int x = a[1] / a[0] + a[2] / a[0];
    if(x > 5){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}