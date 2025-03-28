#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n == 1){
        cout << "YES" << endl;
        return;
    }
    if(n == 2){
        if(abs(a[1]-a[2]) % 2 == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        return;
    }
    sort(a.begin()+1,a.end());
    for(int i=2;i<=n;i++){
        if((a[i] - a[i-1]) % 2 != 0){
            // cout << -1 << endl;
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}