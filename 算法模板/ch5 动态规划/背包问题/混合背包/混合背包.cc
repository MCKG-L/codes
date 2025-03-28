#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
/*
三种背包问题混合在一起 即每一种物品可以使用的次数分为三种：只能只用一次，可以无限次使用，可以使用s次
解决方法：首先把多重背包问题转化为01背包问题 将所有的物品处理好，并记录类别
在处理过程中，枚举每一个物品，如果是01背包的类型就使用01背包的状态转移方程，
如果是完全背包问题就使用完全背包的状态转移方程
*/
const int N = 1010;
int n,m;
int f[N];
struct Node{
    int type;
    int v,w;
};
vector<Node> p;
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int v,w,s;
        cin >> v >> w >> s;
        if(s < 0) p.push_back({-1,v,w});
        else if(s == 0) p.push_back({0,v,w});
        else{
            for(int k=1;k<=s;k*=2){
                s -= k;
                p.push_back({-1,v*k,w*k});
            }
            if(s > 0) p.push_back({-1,v*s,w*s});
        }
    }
    for(auto g : p){
        if(g.type < 0){
            for(int j=m;j>=g.v;j--){
                f[j] = max(f[j],f[j-g.v]+g.w);
            }
        }else{
            for(int j=g.v;j<=m;j++){
                f[j] = max(f[j],f[j-g.v] + g.w);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}