#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> l(n+1),r(n+2),a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    l[0] = 0;
    for(int i=1;i<=n;i++){
        l[i] = l[i-1];
        if(a[i] == a[1]) l[i] ++;
    }
    r[n+1] = 0;
    for(int i=n;i>=1;i--){
        r[i] = r[i+1];
        if(a[i] == a[n]) r[i] ++;
    }
    if(a[1] == a[n]){
        cout << (l[n] >= k ? "YES" : "NO") << endl;
        return;
    }
    for(int i=1;i<n;i++){
        if(l[i] >= k &&  r[i+1] >= k){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}