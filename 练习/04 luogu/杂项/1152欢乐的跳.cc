#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;cin >> n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    map<ll,int> mp;
    for(int i=1;i<=n-1;i++){
        int d = abs(a[i]-a[i+1]);
        mp[d]++;
    }
    for(int i=1;i<n;i++){
        if(mp[i] == 0){
            cout << "Not jolly";
            return;
        }
    }
    cout << "Jolly";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}