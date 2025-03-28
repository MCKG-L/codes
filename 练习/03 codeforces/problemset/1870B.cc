#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n,m;cin >> n >> m;
    bool f = n & 0x1ll;
    int M = 0,mn = 0;
    vector<int> a(n),b(m);
    vector<bool> k(32),st(32);
    for(int j=0;j<n;j++){
        cin >> a[j];
        int x = a[j];
        M ^= x;
        for(int i=31;i>=0;i--){
            bool d = x >> i & 1ll;
            k[i] = k[i] ^ d;
        }
    }
    for(int j=0;j<m;j++){
        cin >> b[j];
        int x = b[j];
        for(int i=31;i>=0;i--){
            bool d = x >> i & 1ll;
            if(d == 1) st[i] = 1;
        }
    }
    for(int i=0;i<32;i++){
        if(st[i]) k[i] = k[i] | 1;
    }
    for(int i=0;i<32;i++){
        if(st[i]) mn += f * (1 << i);
        else mn += (1 << i) * k[i];
    }
    cout << min(mn,M) << ' ' << max(mn,M) << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}