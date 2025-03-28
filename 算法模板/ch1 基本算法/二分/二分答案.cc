#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n,x;
/*
可以使用一般的二分方法 也可以使用另一版本
避免判断复杂的边界条件
定义一个变量保存答案 在二分时遇到满足条件的值就直接更新答案
此时二分结束条件修改为l <= r
更新l，r时：满足条件 l = mid + 1,不满足条件 r = mid - 1;
这样可以保证所有可能的答案都会被遍历到 也不用考虑最后跳出循环时l的值（此时l不一定是答案）
*/
bool check(int mid){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += max(0ll,mid-a[i]);
    }
    if(sum <= x) return 1;
    return 0;
}
void solve(){
    cin >> n >> x;
    for(int i=0;i<n;i++) cin >> a[i];
    int l = 1, r = 2e9;
    int ans = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) ans = max(ans,mid),l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}