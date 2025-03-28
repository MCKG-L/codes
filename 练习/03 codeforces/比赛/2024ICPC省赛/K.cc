    #include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    n = a.erase(unique(a.begin(),a.end()),a.end())-a.begin();
    ll ans = -1;
    for(int i=0;i<n;i++) ans = max(ans,(ll)a[i]);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans = max(ans,(ll)(a[i] | a[j]));
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}