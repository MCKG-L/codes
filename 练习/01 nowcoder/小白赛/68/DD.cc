#include <bits/stdc++.h>
using namespace std;
int d[] = {1,-1,10,-10,100,-100,300,-300};
bool vis[310];
int bfs(int a,int s){
    memset(vis,0,sizeof(vis));
    queue<pair<int,int>> que;
    //从两头分别开始宽搜
    que.push({s,0});
    que.push({300,1});
    while(!que.empty()){
        pair<int,int> f;
        f = que.front();
        que.pop();
        if(f.first == a) return f.second;
        for(int i=0;i<8;i++){
            int x = f.first + d[i];
            if(x > 300) x = 300;
            if(x < 10) x = 10;
            if(!vis[x] && x <= 300 && x >= 10){
                que.push({x,f.second + 1});
                vis[x] = 1;
            }
        }
    }
    return 0;
}
void solve(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    ans += bfs(a,10);
    ans += bfs(b,10);
    ans += bfs(c,10);
    ans += bfs(d,10);
    cout << ans << '\n';
 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}