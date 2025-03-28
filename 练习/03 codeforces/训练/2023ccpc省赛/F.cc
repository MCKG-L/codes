#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    vector<int> dif(n + 1);
    for(int i=0;i<n-1;i++) dif[i] = a[i+1] - a[i];
    vector<int> que(n + 1);
    int hh = 0,tt = -1;
    k --;
    int ans = 1e18;
    for(int i=0;i<n-1;i++){
        while(hh <= tt && i-k+1 > que[hh]) hh ++;
        while(hh <= tt && dif[que[tt]] >= dif[i]) tt --;
        que[++tt] = i;
        if(i >= k-1){
            ans = min(ans,dif[que[hh]]*(a[i+1]-a[i-k+1]));
        }
    }
    cout << ans << endl;
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