#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10,INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<int> f1(n+1),f2(n+1);
    int ans1= 0,ans2 = 0;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        if(x > 0){
            f1[i] = f1[i-1] + 1;
            f2[i] = f2[i-1];
        }else{
            f1[i] = f2[i-1];
            f2[i] = f1[i-1] + 1;
        }
        ans1 += f1[i],ans2 += f2[i];
    }
    cout << ans2 << ' ' << ans1 << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}