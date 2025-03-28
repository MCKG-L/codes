#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int a[N],n,k;
void solve(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    vector<int> p;
    for(int i=0;i<n-1;i++){
        int d = a[i+1] - a[i];
        p.push_back(d);
    }
    int cnt = 0,s = 0;
    for(int i=0;i<n-1;i++){
        if(p[i] <= k) cnt ++;
        else{
            s = max(s,cnt);
            cnt = 0;
        }
    }
    if(cnt) s = max(s,cnt);
    cout << n - s - 1 << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}