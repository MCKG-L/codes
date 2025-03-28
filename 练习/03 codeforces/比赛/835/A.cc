#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<PII> p;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        p.push_back({x,i});
    }
    sort(p.begin(),p.end());
    vector<int> ans(n);
    int k = n;
    for(auto [x,y] : p){
        ans[y] = k --;
    }
    for(auto i : ans ) cout << i << ' ';
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}