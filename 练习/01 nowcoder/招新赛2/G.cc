#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 50;
int a[N],n;
bool check(int k){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x = (a[i] % k + k) % k;
        mp[x] ++;
    }
    for(auto [x,y] : mp){
        if(y >= n / 2) return 1;
    }
    return 0;
}
void solve(){
    cin >> n;
    int M = -1e7;
    for(int i=0;i<n;i++){
        cin >> a[i];a[i] += 1e6;
    }
    map<int,int> mp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x = abs(a[i]-a[j]);
            for(int k=1;k<=x/k;k++){
                if(x % k) continue;
                mp[k] ++;mp[x/k] ++;
            }
        }
    }
    if(check(1e7)){
        cout << "Stardew_Valley" << endl;
        return;
    }
    int ans = 0;
    for(auto [x,y] : mp){
        if(check(x)) ans = max(ans,x);
    }
    cout << ans << endl;
}
signed main()
{
    int t = 1;
    cin >> t;
    while(t--) solve();
}