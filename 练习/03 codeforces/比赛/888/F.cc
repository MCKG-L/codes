#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
/*
题目本意是求ai和aj的最大同或值，可以转换为求最小异或
根据结论：最小异或对一定来自排序后的相邻的一对数
计算x：同或最大：相同位尽可能多，在已经找到最大同或对后，想要找到x
只需要尽可能的保留ai,aj的相同位即可，所以x可以取ai在2^k内的反码
*/
pair<int,int> p[N];
void solve(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        p[i] = {x,i};
    }
    sort(p+1,p+1+n);
    int m = 2e9,pos = -1;
    for(int i=1;i<n;i++){
        int t = p[i].first ^ p[i+1].first;
        if(t < m){
            m = t;pos = i;
        }
    }
    int ans = (1<<k)-1-(p[pos].first & p[pos+1].first);
    // for(int i=0;i<k;i++){
    //     if(!(p[pos].first >> i & 1) && !(p[pos+1].first >> i & 1)) ans += 1 << i;
    // }
    cout << p[pos].second << ' ' << p[pos+1].second << ' ' << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}