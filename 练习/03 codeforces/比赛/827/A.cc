#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a == b + c || b == a + c || c == a + b){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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