#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1e6 + 10,inf = 1e18;
/*
有一个无限平面由边长为1的正方形构成，问以其中一个正方形的中心为圆心，半径为R的圆中完全
包含多少个小正方形？

圆心的位置不重要，使圆心坐标为(0,0)，正方形的所有中心坐标在(i,j)上
考虑到圆形的对称性，只需要计算在第一象限和坐标轴上的正方形个数 按列计算，枚举x轴的坐标
二分找到y轴坐标的最大值，统计答案
*/
void solve(){
    int n;cin >> n;
    int ans = 0;
    auto check = [&](int x,int y)->bool{
        return (x + 0.5) * (x + 0.5) + (y + 0.5) * (y + 0.5) <= n * n;
    };
    for(int i=0;i<n;i++){
        int l = 0,r = n;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(check(i,mid)) l = mid + 1;
            else r = mid - 1;
        }
        ans += 4 * r;
    }
    cout << ans + 1 << endl;
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