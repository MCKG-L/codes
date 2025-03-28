#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
void solve(){
    int n,Q;cin >> n >> Q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<PII> q;
    for(int i=1;i<=Q;i++){
        int k;cin >> k;
        q.push_back({k,i});
    }
    vector<int> ans(Q+1);
    sort(q.begin(),q.end());
    int sum = 0;
    for(int i=0,j=1;i<Q;i++){
        auto [k,it] = q[i];
        while(j <= n && k >= a[j]){
            sum += a[j];
            j ++;
        }
        ans[it] = sum;
    }
    for(int i=1;i<=Q;i++) cout << ans[i] << ' ';
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