#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
/*
下证明最长区间一定来自1~x：
如果有连续因子：a1 a2 a3 a4 a5 a6 共6个数，则这6个数中一定有1~6所有数的倍数
因为x的任意两个相邻倍数之间有x-1个数
则从非1开始的任意长度为x的连续因子区间总能找到1~x的连续因子于之对应
即最长连续因子区间从1~x中产生
*/
int n;
void solve(){
    cin >> n;
    int ans = 0;
    for(int i=1;i<=n+1;i++){
        if(n % i != 0){
            cout << i - 1 << endl;
            return;
        }
    }
}
signed main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}