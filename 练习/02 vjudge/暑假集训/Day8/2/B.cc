#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
void solve(){
    int n;cin >> n;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x < 0) a.push_back(-x);
        else b.push_back(x);
    }
    sort(a.begin(),a.end(),[&](int p1,int p2){return p1 > p2;});
    sort(b.begin(),b.end(),[&](int p1,int p2){return p1 > p2;});
    int ans = 0;
    if(b.size() >= 2) ans = b[0] * b[1];
    else if(b.size() == 1){
        ans = -b.back() * a.back();
    }
    if(a.size() >= 2){
        ans = max(a[0] * a[1],ans);
    }else if(a.size() == 1){
        ans = max(ans,-a.back() * b.back());
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}