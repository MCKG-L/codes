#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10;
int n,m;
int k[N],a[N];
vector<PII> p;
bool check(int mid){
    memset(k,0,sizeof k);
    for(int i=0;i<mid;i++){
        auto &[l,r] = p[i];
        k[l] ++;k[r+1] --;
    }
    for(int i=1;i<=n;i++){
        k[i] += k[i-1];
        if(k[i] > a[i]) return 0;
    }
    return 1;
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    int l = 0,r = m;
    while(m--){
        int l,r;cin >> l >> r;
        p.push_back({l,r});
    }
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}
signed main()
{
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}