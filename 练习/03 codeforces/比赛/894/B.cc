#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n;
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(a[i] >= a[i-1]){
            ans.push_back(a[i]);
        }else{
            ans.push_back(a[i]);
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i << ' ' ;
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}