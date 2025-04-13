#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
const int N = 2e5 + 10,mod = 1e9 + 7,inf = 1e18;
void solve(){
    int n;cin >> n;
    vector<int> alls;
    vector<array<int,3>> q;
    for(int i=1;i<=n;i++){
        int l,r;
        cin >> l >> r;
        alls.push_back(l);
        alls.push_back(r);
        q.push_back({l,r,l+r});
    }
    sort(alls.begin(),alls.end());
    int m = alls.erase(unique(alls.begin(),alls.end()),alls.end())-alls.begin();
    auto find = [&](int x)->int{
        return lower_bound(alls.begin(),alls.end(),x)-alls.begin()+1;
    };
    vector<int> a(m + 10);
    for(auto [l,r,c] : q){
        l = find(l),r = find(r);
        a[l] += c;a[r+1] -= c;  
    }
    for(int i=1;i<=m;i++) a[i] += a[i-1];
    int Max = -inf,ans = -inf;
    for(auto x : alls){
        int nx = find(x);
        if(a[nx] > Max){
            Max = a[nx];
            ans = x;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}