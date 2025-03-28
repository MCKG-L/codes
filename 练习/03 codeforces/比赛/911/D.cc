#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 2e9;
vector<int> f(N);
vector<int> alls[N];
void init(){
    f[1] = 1;
    alls[1].push_back(1);
    for(int i=2;i<N;i++){
        f[i] = i;
        for(int j=1;j<=i/j;j++){
            if(i % j == 0){
                f[i] -= f[j];
                alls[i].push_back(j);
                if(i/j != j){
                    alls[i].push_back(i/j);
                    if(i/j != i) f[i] -= f[i/j];
                }
            }
        }
    }
}
void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(),a.end());
    int ans = 0ll;
    vector<int> cnt(N);
    for(int i=0;i<n;i++){
        for(auto x : alls[a[i]]){
            ans += cnt[x] * f[x] * (n - i - 1);
            cnt[x] ++;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--) solve();
    return 0;
}