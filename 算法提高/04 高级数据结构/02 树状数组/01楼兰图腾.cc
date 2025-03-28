#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int t[N],a[N];
int n;
int Lower[N],Greater[N];
int lowbit(int x){
    return x & - x;
}
void add(int x,int d){
    for(int i=x;i<=n;i+=lowbit(i)) t[i] += d;
}
int sum(int x){
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += t[i];
    return res;
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++){
        int y = a[i];
        Greater[i] = sum(n) - sum(y);
        Lower[i] = sum(y-1);
        add(y,1);
    }
    memset(t,0,(n+2)*4);
    int ans1 = 0,ans2 = 0;
    for(int i=n;i>=1;i--){
        int y = a[i];
        ans1 += Greater[i] * (sum(n) - sum(n));
        ans2 += Lower[i] * sum(y-1);
        add(y,1);
    }
    cout << ans1 << ' ' << ans2 << endl;
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
