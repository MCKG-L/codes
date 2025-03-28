#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    vector<bool> st(n+1);
    vector<int> ans;
    for(int i=1;i<=n;i++) cin >> a[i];
    int pre = 0;
    for(int j=1;j<=n;j++){
        int M = -1,p = -1;
        for(int i=1;i<=n;i++){
            if(st[i]) continue;
            int t = a[i] | pre;
            if(t > M){
                M = t;p = i;
            }
        }
        if(M <= pre){
            for(int i=1;i<=n;i++){
                if(st[i] == 0) ans.push_back(a[i]);
            }
            break;
        }else{
            st[p] = 1;
            pre = pre | a[p];
            ans.push_back(a[p]);
        }
    }
    for(auto i : ans) cout << i << ' ';
    cout << endl;
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}