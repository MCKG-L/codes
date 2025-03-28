#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
void solve(){
    vector<int> a(3,0);
    for(int i=0;i<3;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int ans = 0;
    if(a[0] >= 1) ans ++,a[0] --;
    if(a[1] >= 1) ans ++,a[1] --;
    if(a[2] >= 1) ans ++,a[2] --;

    if(a[0] >= 1 && a[2] >= 1){
        ans ++;a[0] --,a[2] --;
    }
    if(a[1] >= 1 && a[2] >= 1){
        ans ++;a[1] --,a[2] --;
    }
    if(a[0] >= 1 && a[1] >= 1){
        ans ++;a[0] --,a[1] --;
    }
    if(a[0] >= 1 && a[1] >= 1 && a[2] >= 1) ans ++;
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}