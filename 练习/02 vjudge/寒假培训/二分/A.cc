#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll,int> mp;
ll m_find(ll x,ll a[],int i){
    if(mp[x] != 0) return mp[x];
    int l = 0,r = i - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(a[mid] >= x){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    int ans = 0;
    while(a[l++] == x) ans++;
    mp[x] = ans;
    return ans;
}
void solve(){
    int n,c;
    cin >> n >> c;
    ll ans=0,a[n] = {};
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        ans += m_find(a[i]-c,a,i);
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}