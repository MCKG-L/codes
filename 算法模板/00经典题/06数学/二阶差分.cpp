#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 1e5 + 10;
/*abc_407_f
分类讨论+二阶差分 区间加等差数列 可以转化为二阶差分的少数点修改（区间加定值转化为一阶差分单点修改）
题意：对于1<=k<=n，统计所有长度为k的子序列的最大值的和
直接求不好求，考虑拆每一位的贡献，发现以a[i]作为最大值的区间是可以预处理出来的
记l[i]为a[i]左边小于等于它的个数，r[i]为a[i]右边严格小于它的个数
则可以得知以a[i]作为最大值的区间长度为1~l[i]+r[i]+1,区间长度j不同时，造成的贡献是不同的
下面分类讨论：记X1=min(l[i],r[i]),X2=max(l[i],r[i])
当1<=j<=x1+1时：ans[j] += j
当x1+2<=j<=x2+1时：ans[j] += x1 + 1;
当x2+2<=j<=x1+x2+1时：ans[j] += x1 + x2 + 2 - j
转化为区间加问题（区间加等差数列）,可以转化为二阶差分数组的单点修改:
修改序列：1 2 3 4 ... x1+1|x1+1 x1+1 ... x1+1|x1+1 x1 x1-1 ... 1|0 0 0...0
差分一次：1 1 1 1 ...1|0 0 0 ... 0|-1 -1 ... -1|-1 0 0 ...0
差分二次：1 0 0 0 ...0|-1 0 0 ...0|-1 0 0 ... 0|0 1 0 0...0
即转化为d[1]+=a[i],d[x1+2]-=a[i],d[x2+2]-=a[i],d[x1+x2+2]+=a[i]
*/
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1),l(n + 10),r(n + 10);
    vector<int> stk(n + 10);
    int top = 0;
    for(int i=1;i<=n;i++){
        int x;cin >> x;a[i] = x;
        while(top && a[stk[top]] <= x) top --;
        l[i] = i - (top ? stk[top] + 1 : 1);
        stk[++top] = i;
    }
    stk.resize(n + 10),top = 0;
    for(int i=n;i>=1;i--){
        int x = a[i];
        while(top && a[stk[top]] < x) top --;
        r[i] = (top ? stk[top] - 1 : n) - i;
        stk[++top] = i;
    }
    vector<int> d(n + 10);
    for(int i=1;i<=n;i++){
        int x1 = min(l[i],r[i]);
        int x2 = max(l[i],r[i]);
        d[1] += a[i];
        d[x1+2] -= a[i];
        d[x2+2] -= a[i];
        d[x1+x2+3] += a[i];
    }
    for(int i=1;i<=n;i++) d[i] += d[i-1];
    for(int i=1;i<=n;i++){
        d[i] += d[i-1];
        cout << d[i] << '\n';
    }
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