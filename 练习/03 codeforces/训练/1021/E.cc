#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
// typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i] % 2 == 0){
            cout << 1 << '\n' << i <<  endl;
            return;
        }
    }
    int cnt = 0;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(a[i] & 1){
            cnt ++;ans.push_back(i);
            if(cnt == 2){
                cout << 2 << '\n';
                for(auto i : ans) cout << i << ' ';
                cout << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}