#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int n;cin >> n;
    map<int,int> mp;
    for(int i=0;i<n*(n-1)/2;i++){
        int x;cin >> x;
        mp[x] ++;
    }
    int k = n - 1;
    vector<int> ans;
    for(auto [x,y] : mp){
        while(y){
            ans.push_back(x);
            y -= k;
            k --;
        }
    }
    ans.push_back(1e9);
    for(auto i : ans) cout << i << ' ';
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}