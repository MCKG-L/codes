#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n;cin >> n;
    double x = 1.0;
    for(int i=2;i<=n;i++){
        x = x - (x * x) / 3.0;
    }
    printf("%.4f",x);
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}