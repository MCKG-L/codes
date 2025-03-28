#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;
// 二分 + 差分 + 前缀和
const int N = 1e6 + 10;
int a[N],l[N],r[N],d[N];
int s[N],n,m;
bool check(int mid){
    memset(s,0,sizeof s);
    for(int i=1;i<=mid;i++){
        s[l[i]] += d[i];
        s[r[i]+1] -= d[i];
    }
    for(int i=1;i<=n;i++){
        s[i] += s[i-1];
        if(s[i] > a[i]) return 0;
    }
    return 1;
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> d[i] >> l[i] >> r[i];
    int L = 1,R = m;
    while(L < R){
        int mid = L + R >> 1;
        if(check(mid)) L = mid + 1;
        else R = mid;
    }
    if(L == m) cout << 0 << endl;
    else cout << -1 << endl << L << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}