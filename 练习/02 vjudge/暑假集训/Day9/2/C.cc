#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
vector<array<int,3>> p;
void solve(){
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int a,b;cin >> a >> b;
        p.push_back({a,b,i+1});
    }
    sort(p.begin(),p.end(),[&](array<int,3> p1,array<int,3> p2){
        int d = p1[0]*p2[1] - p1[1]*p2[0];
        if(d != 0) return d > 0;
        return p1.back() < p2.back();
    });
    for(auto v : p){
        cout << v.back() << ' ';
    }
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}