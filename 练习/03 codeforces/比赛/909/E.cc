#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    int m = 2e9,p = -1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] < m){
            m = a[i];
            p = i;
        }
    }
    for(int i=p+1;i<n-1;i++){
        if(a[i] > a[i+1]){
            cout << -1 << endl;
            return;
        }
    }
    cout << p << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}