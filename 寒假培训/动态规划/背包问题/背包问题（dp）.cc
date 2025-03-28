#include <bits/stdc++.h>
using namespace std;
/*
    背包问题
    N个物品 Wi、vi分别表示第i个物品的重量和价值，背包容量为bag
    问怎样组合才能使得背包装的物品总价值最高，返回最高价值
    7 15
    3 2 4 7 3 1 7
    5 6 3 19 12 4 3
*/
int w[100],v[100],n,dp[100][100];
//考虑从index~n-1
int maxValue(int bag){
    
    //核心代码
    for(int index=n-1;index>=0;index--){
        for(int rest=0;rest<=bag;rest++){
            int p1 = 0;
            if(rest >= w[index]) p1 = dp[index+1][rest-w[index]] + v[index];
            int p2 = dp[index+1][rest];
            dp[index][rest] = max(p1,p2);
        }
    }
    cout << "ans: ";
    return dp[0][bag];
}
int mp[100][100];
//考虑0~i
int solve(int bag){
    for(int i=0;i<=bag;i++){
        mp[0][i] = i >= w[0] ? v[0] : 0;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=bag;j++){
            int p1 = 0;
            if(j >= w[i]) p1 = v[i] + mp[i-1][j-w[i]];
            int p2 = mp[i-1][j];
            mp[i][j] = max(p1,p2);
        }
    }
    cout << "ans: ";
    return mp[n-1][bag];
}
int main()
{
    int bag;
    cin >> n >> bag;
    for(int i=0;i<n;i++){
        cin >> w[i];
    }
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cout << maxValue(bag);
    cout << endl;
    cout << solve(bag);
}