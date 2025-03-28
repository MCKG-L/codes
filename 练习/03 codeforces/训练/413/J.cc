#include <iostream>
#include <map>
#include <vector>
#define endl '\n'
#define int long long
using namespace std;
//二进制位表示第i个知识点的状态 折半搜索
void solve(){
    int n,p;cin >> n >> p;
    vector<int> a(n);//每个人的所有知识点掌握状态映射到二进制位 1->掌握 0->不掌握
    for(int i=0;i<n;++i){
        int k;cin >> k;
        int v = 0;
        while(k--){
            int x;cin >> x;
            v |= (1ll << (x-1));//第x个知识点掌握
        }
        a[i] = v;
    }
    //折半 先枚举一半人的所有组队方式 并记录合法的组队
    int l = n / 2,r = n / 2 + n % 2;
    //l个人的组合方式有2^l种 对应l位二进制位状态
    map<int,int> mp;//记录前l个人的各种合法的组队方式
    for(int i=0;i<(1ll<<l);++i){
        int x = i,v = 0;
        bool flag = true;
        for(int j=0;j<l;++j){
            if(x & (1ll << j)){//第j个人在队伍中
                //如果存在知识点重复，则该种组队方式不合法
                if(v & a[j]){
                    flag = false;
                    break;
                }
                //更新队伍的知识点掌握状态
                v |= a[j];
            }
        }
        if(flag) mp[v] ++;
    }
    //枚举剩下r人的所有组队方式
    int ans = 0;
    for(int i=0;i<(1ll<<r);++i){
        int x = i << l;
        int v = 0;
        bool flag = true;
        for(int j=l;j<n;++j){
            if(x & (1ll<<j)){//第j个人在队伍中
                if(v & a[j]){
                    flag = false;
                    break;
                }
                v |= a[j];
            }
        }
        //p个知识点全部掌握对应二进制状态位1ll<<p-1 ->p个1
        //此时v表示r人的一种组队方式对应的知识点掌握状态
        // 1ll<<p-1-v 就是该种组队在l个人组队中所需要的状态
        if(flag) ans += mp[(1ll<<p)-1-v];
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}