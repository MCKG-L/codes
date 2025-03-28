#include <iostream>
using namespace std;
const int N = 55;
int n,a[N];
int up[N],down[N];//up[i]表示第i个上升子序列的最后一个数，down类似
int ans;//全局变量记录最小值
void dfs(int u,int v,int t){
    //t表示当前考虑到第t个数 u表示当前已经有u个上升子序列
    //v表示当前已经有v个下降子序列
    if(u + v >= ans) return;//不是最优解 剪枝
    if(t == n){
        ans = u + v;//找到一组更优解
        return;
    }
    //把第t个数放到上升子序列中，不能放则再开辟一个新的上升子序列
    int k = 1;
    //贪心策略 在a[t]能放入的子序列中找到最后一个元素最大的 这样更有利于最优解（使用的序列数最少）
    //up数组是从大到小排好序的，因为只有当在up中找不到满足小于a[t]的数时才会额外开辟新的子序列
    //从前往后找到第一个小于a[t]的位置 把a[t]加入到这个序列的末尾
    
    for(k=1;k<=u;k++){
        if(up[k] < a[t]) break;
    }
    int temp = up[k];
    up[k] = a[t];
    if(k <= u) dfs(u,v,t+1);
    else dfs(u+1,v,t+1);
    up[k] = temp;//回溯 恢复现场
    //把第t个数放入到下降子序列中 同样的贪心策略
    
    for(k=1;k<=v;k++){
        if(down[k] > a[t]) break;
    }
    temp = down[k];
    down[k] = a[t];
    if(k <= v) dfs(u,v,t+1);
    else dfs(u,v+1,t+1);
    down[k] = temp;
}
int main()
{
    while(cin >> n){
        if(n == 0) break;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        ans = n;
        dfs(0,0,0);
        cout << ans << endl;
    }
    return 0;
}