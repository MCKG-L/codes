#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> ans;
    int M = -1,m = 2e9;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        M = max(M,x);
        m = min(m,x);
    }
    while(M != m){
        if(m % 2 == 1 && M % 2 == 0){
            m = (m + 1) / 2;
            M /= 2;
            ans.push_back(1);
        }else{
            ans.push_back(0);
            m /= 2;
            M /= 2;
        }
    }
    cout << ans.size() << endl;
    if(ans.size() > 0 && ans.size() <= n){
        for(auto i : ans) cout << i << ' ';
        cout << endl;
    }
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}