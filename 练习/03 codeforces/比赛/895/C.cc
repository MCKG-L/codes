#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int l,r;cin >> l >> r;
    if(r < 4){
        cout << -1 << endl;
        return;
    }
    if(r - l + 1 >= 2){
        int i = r;
        while(i % 2) i --;
        cout << i/2 << ' ' << i/2 << endl;
    }else{
        int x = l;
        int q = sqrt(x);
        for(int i=1;i<=q;i++){
            int b = x - i;
            if(__gcd(i,b) != 1){
                cout << i << ' ' << b << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}