#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
using i128 = __int128_t;//GNU G++ 9.2.0才支持
const int N = 2e5 + 10;
int a[N],n;
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int st = 1,ed = n;
    while(st <= n && a[st] == 1) st ++;
    while(ed >= 1 && a[ed] == 1) ed --;
    if(st > ed){ //全1
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    //判断所有数的乘积是否大于1e9 如果大于这个值，则答案就是[st,ed]
    //如果所有的数乘积大于1e9,极限情况是2111....11111e9,此时不使用1e9,和为1e9 + 2e5
    // 而使用后 和为2e9，显然使用后和更大，其余情况类似
    i128 mul = 1;
    for(int i=1;i<=n;i++){
        mul *= a[i];
        if(mul > 1e9){
            cout << st << ' ' << ed << endl;
            return;
        }
    }
    //如果乘积小于2e14,则大于1的元素个数小于50 可以枚举所有的位置
    vector<int> pre_sum(n+1),pre_mul(n+1);
    pre_mul[0] = 1;
    vector<int> p;//大于1的元素位置

    for(int i=1;i<=n;i++){
        if(a[i] > 1) p.push_back(i);
        pre_sum[i] = pre_sum[i-1] + a[i];
        pre_mul[i] = pre_mul[i-1] * a[i];
    }
    // for(auto i : p) cout << i << ' ';
    // cout << endl;
    int M = -1;
    array<int,2> ans = {0};
    n = p.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int l = p[i],r = p[j];
            int d = pre_mul[r]/pre_mul[l-1]-(pre_sum[r]-pre_sum[l-1]);
            if(d > M){
                M = d;
                ans = {l,r};
            }
        }
    }
    cout << ans[0] << ' ' << ans[1] << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}