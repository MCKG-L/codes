#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
/*贪心 如果最终最优状态下，u、v可以合并，则Su + Sv >= u*v*c
假设u > 1 && v > 1，Su >= Sv,则Su + Sv >= 2*u*c -> Su >= u*c -> Su + S1 >= u*c
所以节点u一定可以和节点1合并，所以只需要考虑最优状态下，1是否可以和其他所有节点合并即可
其他节点的a[i]-i*c按照从大到小排序，按照这个合并顺序是最优的
*/
void solve(){
    int n,c;cin >> n >> c;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<PII> p;
    for(int i=2;i<=n;i++){
        p.push_back({a[i]-i*c,i});
    }
    sort(p.begin(),p.end(),greater<PII>());
    int s = a[1];
    for(auto [x,i] : p){
        if(s + x >= 0) s += a[i];
        else{
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}