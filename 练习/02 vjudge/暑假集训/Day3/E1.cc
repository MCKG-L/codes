#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 10;
int x[N];
int n,m,q;
vector<pair<int,int>> seg;
bool check(int mid){
    vector<int> sum(n + 1);
    for(int i=1;i<=mid;i++) sum[x[i]] ++;
    //前缀和
    for(int i=1;i<=n;i++) sum[i] += sum[i-1];
    for(int i=0;i<m;i++){
        int l = seg[i].first,r = seg[i].second;
        if(2*(sum[r]-sum[l-1])>r-l+1) return true;
    }
    return false;
}
void solve(){
    seg.clear();
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        seg.push_back(make_pair(l,r));
    }
    cin >> q;
    for(int i=1;i<=q;i++) cin >> x[i];
    int l = 1,r = q;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(check(l)) cout << l << endl;
    else cout << -1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}