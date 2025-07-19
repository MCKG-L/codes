#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 5e5 + 10,mod = 1e9 + 7,inf = 1e18;
int tr[N],n,m;
/* abs_378_e
求所有子区间和的和，子区间和取模，结果不取模

给定一个长度为N的数组，其子区间的价值为该区间的元素之和模M，求给数组的所有子区间的价值和

首先使用前缀和转化，sum[1<=l<=r<=n]{pre[r]-pre[l-1]}
sum[i=1~n][j=0~i-1]{pre[i]-pre[j]}
sum[i=1~n]{i*pre[i]-sum[j=0~i-1]{pre[j]}}
直观上来看，仍是对N^2个区间求和，但是上式中pre[i]-pre[j]可能为负数，与该区间的真实值相差M(模数)
则最终答案即为上式求和加上补偿值，需要补偿k个M，其中k是pre数组的逆序对数
*/
int lowbit(int x){return x & -x;}
void add(int x,int c){
    while(x <= m){
        tr[x] += c;
        x += lowbit(x);
    }
}
int get(int x){
    int ans = 0;
    while(x){
        ans += tr[x];
        x -= lowbit(x);
    }
    return ans;
}
void solve(){
    cin >> n;cin >> m;
    vector<int> a(n + 2);
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        a[i] = (a[i-1] + x) % m;
    }
    int ans = 0,pre = 0,cnt = 0;
    for(int i=1;i<=n;i++){
        //注意本题中的a[i]范围是[0,m-1],需要加一个偏移量
        cnt += get(m) - get(a[i]+1);//求逆序对数
        ans += i * a[i] - pre;
        pre += a[i];
        add(a[i]+1,1);
    }
    cout << ans + cnt * m << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}