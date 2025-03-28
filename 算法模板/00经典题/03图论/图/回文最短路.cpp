#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10;
/*
题目来源：abc_394_E
给定(i,j)的连接情况，求i->j的最短回文路径长度
考虑回文路径的生成条件 cSc ==> 只有当S是回文串且两端相同时，才可以构造出新的回文串
将(1,1),(1,2),(1,3)....视为节点，原点(0,0)到(i,j)的最短路即i->j的最短回文路径长度，
需要保证所有的路径都是合理的回文串生成路径
初始化：
1、当C(i,j) != '-'时,(0,0)-->(i,j)建立单向边，权重为1，表示从(0,0)(空串)到(i,j)可以生成回文长度为1的路径
2、建立(0,0)-->(i,i)的单向边，权重为0，因为(i,i)本身可满足长度为0的回文路径
3、对于点对(i,j)和(k,l),当C(k,i) == C(j,l) != '-'时，可以从i-->j的回文路径左右各延展一步得到k-->l的回文路径
因为 i-->p1-->p2-->...>pn-->j,又有k--i和j->l的路径标识相同，则可以得到k->i->p1->p2->...->pn->j->l 即(k,l)的回文路径
满足此条件时从(i,j)-->(k,l)建单向边，权重为2
总上(0,0)到(i,j)的最短路，即为i-->j的最短回文路径长度

分析路径权重可知，权重为0和1的点固定，后加入的边权相同，都为2，则可以使用BFS得出答案
先分别将权重为0和1的入队,后续根据BFS顺序得出最短路
*/
void solve(){
    int n;cin >> n;
    vector<vector<char>> g(n+1,vector<char>(n+1));
    int inf = 1e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> g[i][j];
        }
    }
    vector<vector<int>> dis(n+1,vector<int>(n+1,inf));
    queue<PII> q;
    for(int i=1;i<=n;i++){
        q.push({i,i});
        dis[i][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j] != '-' && i != j){
                q.push({i,j});
                dis[i][j] = 1;
            }
        }
    }
    while(q.size()){
        auto [i,j] = q.front();q.pop();
        for(int k=1;k<=n;k++){
            for(int l=1;l<=n;l++){
                if(g[k][i] != '-' && g[j][l] != '-' && g[k][i] == g[j][l] && dis[k][l] == inf){
                    dis[k][l] = dis[i][j] + 2;
                    q.push({k,l});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << (dis[i][j] != inf ? dis[i][j] : -1) << " \n"[j == n];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}