#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n+10),st(n+10);
    for(int i=1;i<=n;i++) cin >> a[i];
    int p = n;
    for(int i=0;i<k;i++){
        if(a[p] > n){
            cout << "No" << endl;
            return;
        }
        if(st[p]){
            cout << "Yes" << endl;
            return;
        }
        st[p] = 1;
        p = ((p - a[p]) % n + n) % n;
    }
    cout << "Yes" << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}