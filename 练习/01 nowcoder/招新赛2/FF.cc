#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 10;
int cnt[N];
int n,m,q;
void solve(){
    cin >> q >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;cin >> x;cnt[x] ++;
        }
    }
    vector<int> p;
    int sum = 0,M = -1;
    for(int i=1;i<=q;i++){
        sum += cnt[i];
        M = max(M,cnt[i]);
    }
    if(2 * M >= sum){
        cout << 2 * M - sum;
        return;
    }
    if(sum & 1) cout << 1 << endl;
    else cout << 0 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}