#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
const int N = 1e5 + 10;
vector<pair<int,int>> seg;
int x[N];
int n,m,q;
bool check(int k){
    vector<int> sum(n+1);
    for(int i=1;i<=k;i++) sum[x[i]]++;
    for(int i=1;i<=n;i++) sum[i] += sum[i-1];
    for(int i=0;i<m;i++){
        int l = seg[i].first,r = seg[i].second;
        if(sum[r]-sum[l-1] >= ((r-l+1)/2+1)) return true;
    }
    return false;
}
void solve(){
    seg.clear();
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        seg.push_back({l,r});
    }
    cin >> q;
    for(int i=1;i<=q;i++) cin >> x[i];
    //二分答案
    int l = 1,r = q;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(check(l)) cout << l << endl;
    else cout << -1 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}