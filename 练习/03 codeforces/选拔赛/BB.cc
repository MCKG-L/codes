#include <iostream>
#include <map>
#include <cstring>
#include <cmath>
#define endl '\n'
using namespace std;
map<int,int> mp;
void solve(int t){
    mp.clear();
    int n,k,m;
    cin >> n >> k >> m;
    int a[n],ans[n];
    memset(ans,0,sizeof ans);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<2*n&&i<m;i++){
        int k = i % n;
        if(mp.count(a[k])){
            ans[k]++;
            mp.erase(a[k]);
        }else{
            mp[a[k]]++;
        }
    }
    int p = m / (2 * n);
    if(p > 1) for(int i=0;i<n;i++) ans[i] *= p;
    // m = m % (2 * n);
    m = (p < 1) ? 0 : (m-p*2*n);
    for(int i=0;i<m;i++){
        int k = i % n;
        if(mp.count(a[k])){
            ans[k] ++;
            mp.erase(a[k]);
        }else{
            mp[a[k]]++;
        }
    }
    for(int i=0;i<n;i++) {
        cout << ans[i];
        if(i != n-1) cout << ' ';
    }
    if(t != 1) cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    // while(t--) solve(t);
    while(t){
        solve(t);
        t--;
    }
}