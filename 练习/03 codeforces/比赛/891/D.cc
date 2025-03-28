#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int n;cin >> n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<pair<int,int>> p;
    int M = -2e9;
    for(int i=1;i<=n;i++){
        cin >> b[i];
        p.push_back({a[i]-b[i],i});
        M = max(M,a[i]-b[i]);
    }
    // sort(p.begin(),p.end(),[&](pair<int,int> p1,pair<int,int> p2){
    //     return p1.first > p2.first;
    // });
    vector<int> ans;
    for(auto [x,y] : p){
        if(x == M){
            ans.push_back(y);
        }
    } 
    cout << ans.size() << endl;
    for(auto i :ans) cout << i << ' ';
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}