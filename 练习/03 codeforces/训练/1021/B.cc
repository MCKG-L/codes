#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10,INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
//f1[i]表示考虑前i个位置，且最后选择的是第一列的最大值
//f2[i]表示考虑前i个位置，且最后选择的是第二列的最大值
void solve(){
    int n;cin >> n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    vector<int> f1(n+1),f2(n+1);
    f1[1] = a[1];f2[1] = b[1];
    for(int i=2;i<=n;i++){
        f1[i] = max(f1[i-1],f2[i-1] + a[i]);
        f2[i] = max(f2[i-1],f1[i-1] + b[i]);
    }
    cout << max(f1[n],f2[n]) << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}