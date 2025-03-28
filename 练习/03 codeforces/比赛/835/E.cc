#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> b = a;
    for(int i=1;i<=n;i++){
        if(b[i] == 0){
            b[i] = 1;break;
        }
    }
    int cnt = 0,ans = 0;
    for(int i=1;i<=n;i++){
        if(b[i] == 1) cnt ++;
        else ans += cnt;
    }
    cnt = 0;int s = 0;
    for(int i=1;i<=n;i++){
        if(a[i] == 1) cnt ++;
        else s += cnt;
    }
    ans = max(ans,s);
    b = a;
    for(int i=n;i;i--){
        if(b[i] == 1){
            b[i] = 0;
            break;
        }
    }
    cnt = 0;
    int res = 0;
    for(int i=1;i<=n;i++){
        if(b[i] == 1) cnt ++;
        else res += cnt;
    }
    ans = max(ans,res);
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}