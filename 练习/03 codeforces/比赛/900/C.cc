#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
void solve(){
    int n,k,x;
    cin >> n >> k >> x;
    int M = (n-k+n+1)*k/2;
    int m = (1+k)*k/2;
    if(x < m || x > M){
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