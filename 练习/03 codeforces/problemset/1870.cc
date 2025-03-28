#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int n,k,x;
    cin >> n >> k >> x;
    if(x < k - 1 || k > n){
        cout << -1 << endl;
    }else{
        if(x == k) x --;
        cout << k * (k-1) / 2 + (n-k) * x << endl;
    }
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}