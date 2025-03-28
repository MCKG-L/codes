#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int k[N];
bool vis[N];
int a,b,n;
struct p{
    int id,s;
}u;
queue<p> que;
int main()
{
    cin >> n >> a >> b;
    que.push((p){a,0});
    for(int i=1;i<=n;i++) cin >> k[i];
    while(!que.empty()){
        u = que.front();
        que.pop();
        if(u.id == b){
            break;
        }
        //上
        int x = u.id + k[u.id];
        if(x <= n && !vis[x]){
            vis[x] = 1;
            que.push((p){x,u.s+1});
        }
        //下
        int y = u.id - k[u.id];
        if(y >= 1 && !vis[y]){
            vis[y] = 1;
            que.push((p){y,u.s+1});
        }
    }
    if(u.id == b){
        cout << u.s;
    }else{
        cout << -1;
    }
    return 0;
}