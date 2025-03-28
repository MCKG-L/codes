#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    vector<pair<int,int>> p;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a <= 10) p.push_back({b,i+1});
    }
    sort(p.begin(),p.end());
    cout << p.back().second << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}