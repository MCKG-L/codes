#include <bits/stdc++.h>
using namespace std;
/*
    背包问题
    N个物品 Wi、vi分别表示第i个物品的重量和价值，背包容量为bag
    问怎样组合才能使得背包装的物品总价值最高，返回最高价值
    7 15
    3 2 4 7 3 1 7
    5 6 3 19 12 4 2
*/
int w[100],v[100],n,mp[100][100];
//当前考虑到了index货物 每一次
int process(int index,int bag){
    if(mp[index][bag] != -1) return mp[index][bag];

    int ans = 0;
    int p1 = 0;
    if(bag - w[index] < 0) p1 = 0;
    else p1 = v[index] + process(index+1,bag-w[index]);
    int p2 = process(index+1,bag);
    ans = max(p1,p2);
    mp[index][bag] = ans;
    return ans;
    // //base-case
    // if(index == n) return 0;
    // // if(bag < 0) return -1;//重量可能为0 在下面已经提前判断 排除了这种情况
    // //index号货物拿了
    // int p1;
    // if(bag - w[index] < 0) p1 = 0;
    // else p1 =  v[index] + process(index+1,bag-w[index]);
    // //index号货物不拿
    // int p2 = process(index+1,bag);
    // return max(p1,p2);
}
void maxValue(int bag){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=bag;j++){
            mp[i][j] = -1;
        }
    }
    int ans = process(0,bag);
    cout << "mp: \n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=bag;j++){
            printf("%2d ",mp[i][j]);
        }
        cout << endl;
    }
    cout << "ans: " << ans;
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
    maxValue(bag);
    return 0;
}