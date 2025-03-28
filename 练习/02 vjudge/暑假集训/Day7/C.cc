#include <iostream>
#include <map>
#define endl '\n'
using namespace std;
/*
题意：给定一个数组，每次操作可以将任意一个后缀子段的异或和加入到数组的最后

可以加入到数组最后的一定是原数组出现过的连续子段的异或和，并且出现过的连续子段
异或和都可以经过两步操作加入到数组最后(利用x^x=0,把相应的后缀子段重复加入，相互抵消)

转化为求：原数组中出现过的最大的连续子段异或和
方法：记录所有前缀子段的异或和 利用x ^ x = 0的性质可以枚举出任意连续子段的异或和

eg: 8 2 4 12 1
当枚举到1时，此时所有数的异或和为s，所有前缀异或和已经计算出(包括0)
将s分别与每一个前缀异或和求异或，可以得到每一个后缀异或和
这样数组从前往后枚举，就可以枚举出所有的连续子段异或和，求最大值即可
*/
map<int,bool> mp;
void solve(){
    int n;cin >> n;
    mp.clear();mp[0] = 1;
    int ans = 0,s = 0,x = 0;
    for(int i=0;i<n;i++){
        cin >> x;s ^= x;mp[s] = 1;
        for(auto [x,y] : mp){
            ans = max(ans,x ^ s);
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}