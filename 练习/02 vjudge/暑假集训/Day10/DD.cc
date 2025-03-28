#include <iostream>
#include <vector>
using namespace std;
const int N = 15;
bool st[N][N];
vector<int> p[N];
int n,t,m;
int ans;
//dfs + 剪枝
/*
直接暴力搜索时，集合元素顺序不同时会认为是不同的方案，造成重复计算
保证分配的t个集合的首元素升序排列 不跳过任一个空集合
*/
void dfs(int u){
    if(u > n){
        for(int i=0;i<t;i++){
            if(p[i].size() == 0) return;
        }
        ans ++;return;
    }
    //遍历所有已有组，考虑第u个人可以加到哪组
    for(int i=0;i<t;i++){
        bool mask = false;
        for(auto it : p[i]){
            if(st[it][u]) mask = true;
        }
        if(!mask){//不冲突
            p[i].push_back(u);
            dfs(u + 1);
            p[i].pop_back();
        }
        if(p[i].size() == 0) return;//去重
    }
}
int main()
{
    cin >> n >> t >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        st[a][b] = st[b][a] = 1;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}