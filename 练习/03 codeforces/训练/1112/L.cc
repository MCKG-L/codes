#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 10010,M = 1e5 + 10;
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> b;
    b.push_back(0);
    for(int i=1;i<=n;i++){
        int j = i;
        while(j <= n && a[j] >= a[j+1]) j ++;
        if(j == n + 1) j = n;
        b.push_back(j-i+1);
        i = j;
    }
    vector<int> pre(n+10);
    int cnt = b.size() - 1;
    int ans = 0;
    for(int i=1;i<=cnt;i++) pre[i] = pre[i-1] + b[i],ans += pre[i];
    int id = 1,d = 0;
    while(b[id] == 1) id ++,d ++;
    for(int i=1;i<=n;i++){
        if(i < cnt){
            cout << -1 << ' ';
            continue;
        }
        cout << ans << ' ';
        d ++,b[id] --;
        ans = ans + d;
        while(id <= cnt && b[id] == 1) id ++,d ++;
    }
    cout << endl;
}
signed main()
{
    IOS;
	int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}