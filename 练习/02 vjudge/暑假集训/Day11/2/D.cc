#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int a[N],n;
void solve(){
    cin >> n;
    a[0] = a[n+1] = 2e9;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i=1,j=1;i<=n;i++){
        while(i <= n && a[i] >= a[i-1]) i ++;
        j = i + 1;
        while(j <= n+1 && a[j] == a[i]) j ++;
        if(i == n+1) break;
        if(a[j] > a[i]){
            // cout << i << ' '<< j-1 << endl;
            cnt ++;
        }
        i = j - 1;
        if(cnt >= 2){
            cout << "NO" << endl;
            return;
        }
    }
    if(cnt == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}