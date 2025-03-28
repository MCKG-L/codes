#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n;cin >> n;
    vector<int> a(n+2);
    a[n+1] = 1e5;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    bool ok = 1;
    int k = 0;
    for(int i=(1<<k);i<=n;i=(1<<k)){
        k ++;
        for(int j=i+1;j<=n&&j<(1<<k);j++){
            if(a[j] > a[j+1]){
                ok = 0;
            }
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}