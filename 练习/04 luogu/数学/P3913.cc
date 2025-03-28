#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;
void solve(){
    int n,k;
    cin >> n >> k;
    unordered_map<int,int> s1,s2;
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        s1[x] ++;
        s2[y] ++;
    }
    int ans =  (s1.size() + s2.size()) * n - s1.size() * s2.size();
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}