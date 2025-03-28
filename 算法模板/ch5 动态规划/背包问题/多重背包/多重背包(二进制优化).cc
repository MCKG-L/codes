#include <iostream>
#include <vector>
using namespace std;
/*
每个物品的个数有限，在背包容量有限厄的情况下，装出价值和最多的物品
*/
const int N = 25000, M = 2010;
int v[N],w[N];
int dp[N];
int n,m;
/*
二进制优化：每一个物品最多使用si次，我们将这si个物品打包成许多份：
1,2,4,8,...,2^k,s
可以证明这些组之间任意组合可以拼凑出来0~si的所有情况（每个组最多选一次）
将每一个物品都打包成许多组，这些组合都是最多选一次的，所以问题转化为了01背包问题
*/
int main()
{
    //时间复杂度 O(NVlogS)
    cin >> n >> m;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        int a,b,s;
        cin >> a >> b >> s;
        int k = 1;
        //打包
        while(k <= s){
            cnt ++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if(s > 0){
            cnt ++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    n = cnt;
    //01背包
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}
//另一种写法
// const int N = 2010;
// int n,m;
// struct Node{
//     int v,w;
// };
// int main()
// {
//     cin >> n >> m;
//     vector<Node> p;
//     for(int i=0;i<n;i++){
//         int v,w,s;
//         cin >> v >> w >> s;
//         for(int k=1;k<=s;k*=2){
//             s -= k;
//             p.push_back({v*k,w*k});
//         }
//         if(s > 0) p.push_back({v*s,w*s});
//     }
    
//     for(auto i : p){
//         for(int j=m;j>=i.v;j--){
//             dp[j] = max(dp[j],dp[j-i.v]+i.w);
//         }
//     }
//     cout << dp[m] << endl;
//     return 0;
// }