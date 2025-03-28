#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;
void solve(){
    int n,m;
    cin >> n >> m;
    int M = max(m,n);
    vector<int> a(M+1),b(M+1);
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        a[n-i+1] = x;
    }
    for(int i=1;i<=m;i++){
        int x;cin >> x;
        b[m-i+1] = x;
    }
    vector<int> ans;
    int t = 0;
    for(int i=1;i<=M;i++){
        t += a[i] + b[i];
        ans.push_back(t%(i+1));
        t /= (i + 1);
    }
    if(t) ans.push_back(t);
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}