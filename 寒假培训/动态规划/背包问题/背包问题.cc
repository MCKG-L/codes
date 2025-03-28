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
int w[100],v[100],n;
//当前考虑到了index货物 index号前的货物不选,index ~ n-1自由选择
int process(int index,int bag){
    //base-case
    if(index == n) return 0;
    // if(bag < 0) return -1;//重量可能为0 在下面已经提前判断 排除了这种情况
    //index号货物拿了
    int p1;
    if(bag - w[index] < 0) p1 = 0;
    else p1 =  v[index] + process(index+1,bag-w[index]);
    //index号货物不拿
    int p2 = process(index+1,bag);
    return max(p1,p2);
}
int maxValue(int bag){
    
    //尝试函数
    return process(0,bag);
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
}