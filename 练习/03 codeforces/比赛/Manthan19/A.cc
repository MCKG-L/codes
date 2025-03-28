#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int a,b,n;
    cin >> a >> b >> n;
    if(n % 3 == 0) cout << a << endl;
    else if(n % 3 == 1) cout << b << endl;
    else cout << (a ^ b) << endl;
}   
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}