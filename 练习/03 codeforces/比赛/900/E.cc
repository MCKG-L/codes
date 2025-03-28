#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int pre[32][N];
int a[N];
bool check(int l,int r,int x){
    int ans = 0;
    for(int i=0;i<32;i++){
        if(pre[i][r]-pre[i][l-1] == r - l + 1){
            ans += (1 << i);
        }
    }
    if(ans >= x) return 1;
    return 0;
}
void solve(){
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        a[i] = x;
        for(int j=0;j<32;j++){
            int d = x >> j & 1;
            pre[j][i] = d;
            pre[j][i] += pre[j][i-1];
        }
    }
    int q;cin >> q;
    while(q--){
        int L,x;
        cin >> L >> x;
        int l = L,r = n;
        int ans = 0;
        while(l <= r){
            int mid = l + r >> 1;
            if(check(L,mid,x)) ans = max(ans,mid),l = mid + 1;
            else r = mid - 1;
        }
        // if(check(L,l,x)) cout << l << ' ';
        // else cout << -1 << ' ';
        cout << (ans ? ans : -1) << ' ';
    }
    cout << endl;
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}