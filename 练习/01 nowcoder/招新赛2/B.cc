#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
void solve(){
    int ans = 0;
    int n;cin >> n;
    vector<PII> p;
    for(int i=0;i<n;i++){
        int x,y;cin >> x >> y;
        p.push_back({x,y});
    }
    map<PII,int> mp1;
    map<array<int,3>,int> mp2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x1 = p[i].first,y1 = p[i].second;
            int x2 = p[j].first,y2 = p[j].second;
            int A = y2 - y1,B = x1 - x2,C = x1*y2 - x2*y1;
            if(A < 0) A = -A,B = -B,C = -C;
            ans += mp1[{A,B}];
            ans -= mp2[{A,B,C}];
            mp1[{A,B}] ++,mp2[{A,B,C}] ++;
        }
    }
    cout << ans/2 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}