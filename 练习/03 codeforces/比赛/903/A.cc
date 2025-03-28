#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
int N,m,n;
int find(int x){
    for(int i=0;i<10;i++){
        int r = N * (1<<i);
        int l = N * (1 << (i-1));
        if(i == 0) l = 0;
        if(x >= l && x < r) return i;
    }
    return x;
}
void solve(){
    string s,x;
    cin >> n >> m;
    N = n;
    cin >> x >> s;
    int ans = 0;
    if(x == s){
        cout << 0 << endl;
        return;
    }
    for(int i=0;i<6;i++) x = x + x;
    n = x.size();
    // cout << x << endl;
    for(int i=0;i<n-m;i++){
        string ss = x.substr(i,m);
        // cout << ss << endl;
        if(ss == s){
            int t = i + m;
            cout << find(t) << endl;
            return;
        }
    }
    cout << -1 << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}