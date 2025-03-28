#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,M = 5e5 + 10;

void solve(){
    int n;cin >> n;
    if(n % 3 == 0){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
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