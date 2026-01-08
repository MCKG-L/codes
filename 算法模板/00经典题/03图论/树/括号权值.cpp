#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 3e5 + 10,M = 32,mod = 1e9 + 7,inf = 1e18;
/*https://www.matiji.net/exam/brushquestion/53/4693/305EE97B0D5E361DE6A28CD18C929AF0
给出一个合理的括号序列s，定义一个括号序列的权值为最大的嵌套数
求s的所有合理的字串的权值之和
转化为树上问题：
嵌套关系作为儿子节点，并列关系作为兄弟节点，则一个子树的高度则为对应字串的权值
发现若要满足字串是合法的，则一个子树必须同时选择(整个嵌套)
若u有m个子节点v的深度如下：
3 2 6 5 1 8
则u的贡献为：该序列的所有长度的连续子序列最大值的和
使用单调栈可以解决
*/
void solve(){
    string s;cin >> s;
    int idx = 0;
    int n = count(s.begin(),s.end(),'(');
    vector<vector<int>> a(n + 1);
    vector<int> fa(n + 1);
    auto build = [&](auto build,int u,int pos)->void{
        if(pos >= s.length()){
            return;
        }
        if(s[pos] == '('){
            idx ++;
            a[u].push_back(idx);
            fa[idx] = u;
            build(build,idx,pos+1);
        }else{
            build(build,fa[u],pos+1);
        }
    };
    build(build,0,0);
    vector<int> dep(n + 1);
    vector<PII> stk(n + 1);
    int top = 0,ans = 0;
    vector<int> l(n + 1),r(n + 1);
    auto dfs = [&](auto dfs,int u)->void{
        dep[u] = 1;
        for(auto v : a[u]){
            dfs(dfs,v);
            dep[u] = max(dep[u],dep[v] + 1);
        }
        for(int i=0;i<a[u].size();i++){
            int v = a[u][i];
            while(top && dep[v] > stk[top].first){
                r[stk[top].second] = i;
                top --;
            }
            l[i] = top ? stk[top].second : -1;
            stk[++top] = {dep[v],i};
        }
        while(top){
            r[stk[top].second] = a[u].size();
            top --;
        }
        for(int i=0;i<a[u].size();i++){
            ans += dep[a[u][i]] * (i - l[i]) * (r[i] - i);
        }
    };  
    dfs(dfs,0);
    cout << ans << endl;
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
