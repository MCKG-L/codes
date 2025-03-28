#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
int f[N];//表示删掉第i个数后对总的有价值数的影响
void solve(){
    int n;cin >> n;
    int M = 0,m = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x > M){//x是当前最大值
            m = M,M = x;
            f[x] --;
        }else if(x >= m){//x是次大值
            f[M] ++;
            m = x;
        }
    }
    int ans = 1;
    for(int i=2;i<=n;i++){
        if(f[i] > f[ans]){
            ans = i;
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}