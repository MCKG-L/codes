#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 5e3 + 10,M = 1e5 + 10;
/*
给出一个最多有一个连通块（由1组成的）的n*m的01矩阵,问：
在这个矩阵中让不超过k个0变成1，保证得到的矩阵恰好有一个连通块
问有多少种合理的方案？
1 <= n,m <= 10,0 <= k <= 5
爆搜 + 本质不同的判断（平移、旋转、镜像）
归一化处理
*/
struct Node{
    int x,y;
    bool operator<(const Node p1)const{
        if(x != p1.x) return x < p1.x;
        return y < p1.y;
    }
    void xz(){
        int t = x;
        x = y;
        y = -t;
    }
    void f_x(){
        y = -y;
    }
    void f_y(){
        x = -x;
    }
};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
void solve(){
    int k,n,m;
    cin >> k >> n >> m;
    vector<vector<int>> g(n + 1,vector<int>(m + 1));
    vector<vector<bool>> st(n + 1,vector<bool>(m + 1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> g[i][j];
    }
    int num = 0;
    auto dfs0 = [&](auto dfs0,int x,int y)->void{
        st[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx = x + dx[i],ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(st[nx][ny] || g[nx][ny] == 0) continue;
            dfs0(dfs0,nx,ny);
        }
    };  
    //计算连通块个数
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                if(g[i][j] == 1 && !st[i][j]){
                num ++;
                dfs0(dfs0,i,j);
            }
        }
    }
    //不满足题意
    if(num > 1){
        cout << -1 << endl;
        return;
    }
    //初始不含1
    if(num == 0){
        if(k == 0){
            cout << 0 << endl;
            return;
        }
        k --;
        //任意让一个位置为1，本质不同的前提下，可以任意取一个位置（会经过归一化）
        g[1][1] = 1;
    }
    vector<Node> alls;
    //只存储1的位置
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]) alls.push_back({i,j});
        }
    }
    //归一化到第一象限
    auto Norm = [&](vector<Node> &g)->void{
        sort(g.begin(),g.end());
        auto [x0,y0] = g[0];
        for(auto &t : g) t.x -= x0,t.y -= y0;
    };
    set<vector<Node>> ans;
    auto get_x = [&](vector<Node> alls)->int{
        int mi = inf,mx = -inf;
        for(auto [x,_] : alls){
            mi = min(mi,x);
            mx = max(mx,x);
        }
        return mx - mi + 1;
    };
    auto get_y = [&](vector<Node> alls)->int{
        int mi = inf,mx = -inf;
        for(auto [_,y] : alls){
            mi = min(mi,y);
            mx = max(mx,y);
        }
        return mx - mi + 1;
    };
    //判断是否本质不同
    auto check = [&](vector<Node> alls)->bool{
        int lenx = get_x(alls),leny = get_y(alls);
        if((lenx <= n && leny <= m)||(lenx <= m && leny <= n)){
            vector<Node> g1,g2;
            for(int i=0;i<4;i++){
                //rotate
                for(auto &node : alls) node.xz();
                Norm(alls);                
                if(ans.count(alls)) return 0;

                //f_x
                g1 = alls;
                for(auto &node : g1) node.f_x();
                Norm(g1);
                if(ans.count(g1)) return 0;

                //f_y
                g2 = alls;
                for(auto &node : g2) node.f_y();
                Norm(g2);
                if(ans.count(g2)) return 0;
            }
            return 1;
        }else{
            return 0;
        }
    };
    //爆搜
    auto dfs = [&](auto dfs,vector<Node> alls,int w)->void{
        ans.insert(alls);
        if(w == 0) return;
        set<Node> st;
        for(auto node : alls) st.insert(node);
        for(auto [x,y] : alls){ 
            for(int i=0;i<4;i++){
                int nx = x + dx[i],ny = y + dy[i];
                if(st.count({nx,ny})) continue;
                st.insert({nx,ny});
                vector<Node> tmp = alls;
                tmp.push_back({nx,ny});
                Norm(tmp);
                if(check(tmp)) dfs(dfs,tmp,w-1);
            }
        }
    };
    Norm(alls);
    dfs(dfs,alls,k);
    cout << ans.size() << endl;
}   
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}
