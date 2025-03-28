#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1e6 + 10,inf = 1e18;
/* abc_393_f
给出一个长度为n的序列A，有q个询问，询问的格式为：
R X，要求在A中前R个数中由不大于X的数组成的最长上升子序列的长度是多少？

用到了求LIS的优化方式，基于贪心+二分的方法：
数组s[i]表示长度为i的子序列中，最后一个元素的最小值，易知S序列是单调递增的
基于这种方法 求 LIS的思路为，考虑应该接在哪一个子序列后面，即应该在小于x的最后一个位置上

对于本问题，可以充分利用这个思路，将所有询问离线处理，按照R排序，在求LIS的过程中即可找到对应答案
此时已知任意长度的上升子序列的最后一个元素的最小值(s[i])，要找到前i个数中由不大于x的数组成的LIS，
可以在s中二分找到 不大于x的最后一个位置，即为该询问答案
*/
void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> s(n+1),a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<array<int,3>> query(q);
    for(int i=0;i<q;i++){
        int u,v;
        cin >> u >> v;
        query[i] = {u,v,i};
    }
    s[0] = -inf;
    int len = 0,idx = 0;
    sort(query.begin(),query.end());
    vector<int> ans(q);
    for(int i=1;i<=n;i++){
        int l = 0,r = len;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(s[mid] < a[i]) l = mid + 1;
            else r = mid - 1;
        }
        // 2 5 6 5 2 1 7 9 7 2
        len = max(len,r+1);
        s[r+1] = a[i];
        // cerr << "len: " << len << endl;
        while(idx < q && query[idx][0] == i){
            int x = query[idx][1],id = query[idx][2];
            int l = 0,r = len;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(s[mid] <= x) l = mid + 1;
                else r = mid - 1;
            }
            // cerr << i << ' ' << x << ' ' << r << endl;
            ans[id] = r;
            idx ++;
        }
    }
    for(auto x : ans) cout << x << '\n';
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