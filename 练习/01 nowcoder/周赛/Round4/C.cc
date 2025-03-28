#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10,mod = 1e9 + 7;
int a[N],n,k;
ll ans = 0;
int main()
{
    cin >> n >> k;
    ll add = 0,mn = 1e9;
    for(int i=0;i<n;i++) cin >> a[i];
    while(k--){
        int op,x;
        cin >> op >> x;
        if(op == 1) add += x;
        else add -= x;
        mn = min(mn,add);
        /*记录加减过程中变化量的最小值
        对于一个数a[i]，如果a[i]+mn < 0 说明操作到变化量位mn时，原数变为负，赋值位0
        可以证明后面的所有操作得到的变化量一定时非负数，因为mn记录的时整个操作中的变化量最小值
        最终a[i]将变为最小时刻之后所有操作的变化量之和
        */
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(mn + a[i] >= 0){
            ans = (ans + add + a[i]) % mod;
        }else{
            ans = (ans + add - mn) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}