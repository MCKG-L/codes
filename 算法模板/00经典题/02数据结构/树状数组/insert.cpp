#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 5e5 + 10,mod = 1e9 + 7,inf = 1e18;
/* abc_392_f
树状数组
初始时有一个空数组 A。按 i=1,2,…,N 的顺序依次执行以下操作：
    将数字 i 插入到 A 的前数第 Pi​ 个位置。
    更准确地说，将 A 替换为「A 的前 Pi​−1 个元素」「数字 i」「A 的第 Pi​ 个元素及之后的元素」按此顺序连接后的结果。
请输出所有操作完成后最终的数组 A。

倒序操作，发现每次操作的位置是固定的，即将i插入到当前数组的第p[i]个空位上
使用树状数组的倍增思想找到第p[i]个空位
*/
int tr[N],n;
int lowbit(int x){
    return x & -x;
}
void add(int x,int t){
    for(;x<=n;x+=lowbit(x)) tr[x] += t;
}
void solve(){
    cin >> n;
    vector<int> p(n + 1);
    for(int i=1;i<=n;i++) cin >> p[i],tr[i] = i & -i;
    vector<int> k(n + 1);
    for(int i=n;i>=1;i--){
        int sum = 0,now = 0;
        for(int j=20;j>=0;j--){
            if(now + (1<<j) <= n && sum + tr[now+(1<<j)] < p[i]){
                now += 1 << j;
                sum += tr[now];
            }
        }
        k[i] = now + 1;
        add(now + 1,-1);
    }
    vector<int> ans(n + 1);
    for(int i=1;i<=n;i++) ans[k[i]] = i;
    for(int i=1;i<=n;i++) cout << ans[i] << ' ';
    cout << endl;
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