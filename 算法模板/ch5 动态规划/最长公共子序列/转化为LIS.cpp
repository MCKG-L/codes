#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e3 + 10,M = 1e5 + 10;
/*
给出两个数字序列，最最长公共子序列长度
转化为求最长上升子序列长度：
将A序列的每个元素值A[i],在B数组中的位置（逆序），依次存储保存在新的数组中
3 2 2 1 4 3
3 3 2 1 1 4 2
--->
2 1 7 3 7 3 5 4 6 2 1
LIS:1 3 5 6 --> 3 2 1 4

适用于数据相对随机，位置数组长度最坏为n*m
范围很大时，需要离散化
*/
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n + 1),b(m + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    vector<int> p;p.reserve(1e6);
    p.push_back(0);
    vector<vector<int>> pos(n + 1);
    for(int i=1;i<=m;i++){
        pos[b[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        auto &c = pos[a[i]];
        if(c.size() == 0) continue;
        for(int j=c.size()-1;j>=0;j--){
            p.push_back(c[j]);
        }
    }
    n = p.size();
    vector<int> d(n + 1);
    int len = 1;
    d[1] = p[1];
    for(int i=2;i<=n;i++){
        int l = 1,r = len;
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(d[mid] < p[i]) l = mid + 1;
            else r = mid - 1;
        }
        len = max(len,r+1);
        d[r+1] = p[i];
    }
    cout << len << endl;
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
