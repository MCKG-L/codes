#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
const int N = 110;
void solve(){
    vector<int> a,b,c;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;string op;
        cin >> x >> op;
        if(op[0] == '1') a.push_back(x);
        if(op[1] == '1') b.push_back(x);
        if(op == "11") c.push_back(x);
    }
    if(!a.size() || !b.size()){
        cout << -1 << endl;
    }else{
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        int ans = a[0] + b[0];
        if(c.size()) ans = min(ans,c[0]);
        cout << ans << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}