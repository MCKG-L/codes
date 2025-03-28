#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
//前缀异或和
void solve(){
    int n;cin >> n;
    vector<int> a(n+1),Xor(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];Xor[i] = Xor[i-1] ^ a[i];
    }
    string s;cin >> s;
    vector<int> ans(2,0);
    for(int i=0;i<n;i++){
        ans[s[i]-'0'] ^= a[i+1];
    }
    int q;cin >> q;
    while(q--){
        int op;cin >> op;
        if(op == 1){
            int l,r;cin >> l >> r;
            int t = Xor[r] ^ Xor[l-1];
            ans[0] ^= t,ans[1] ^= t;
        }else{
            int g;cin >> g;
            cout << ans[g] << ' ';
        }
    }
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}