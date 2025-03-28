#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 100010,M = N * 2;
int h[N],e[N],ne[M],idx;
bool st[N];
int ans = N;
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
//dfs遍历
// 返回的是以u为根的子树的大小
int dfs(int u){
    st[u] = 1;
    int sum = 1,res = 0;
    for(int i=h[u];i != -1;i = ne[i]){
        int j = e[i];
        if(!st[j]){//出点
            int s = dfs(j);//以子节点1为根的结点数
            res = max(res,s);//对于u的所有出点，取较大值
            sum += s;//把所有以u的出点为根的结点数加起来，就是以u为根的结点数
        }
    }
    res = max(res,n-sum);//n-sum是以已经算过的出点为根的结点数
    ans = min(res,ans);//按照题意 树的重心要取所有出点的最小值
    return sum;
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        add(a,b),add(b,a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}