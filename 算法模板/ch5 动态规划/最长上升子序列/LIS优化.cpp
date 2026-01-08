#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e3 + 10,M = 1e5 + 10;
/*二分优化 记录长度为len的上升子序列的末尾最小值

*/
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> d(n + 1);
    d[1] = a[1];
    int len = 1;
    for(int i=2;i<=n;i++){
        int l = 1,r = len;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(d[mid] < a[i]) l = mid + 1;
            else r = mid - 1;
        }
        len = max(len,r+1);
        d[r+1] = a[i];
    }
    cout << len << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}
