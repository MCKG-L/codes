#include <iostream>
#include <queue>
using namespace std;
const int N = 210;
int k[N];
int a,b,n;
bool vis[N];
struct node{
    int id,s;
}u;
queue<node> que;

int main()
{
    cin >> n >> a >> b;
    for(int i=1;i<=n;i++) cin >> k[i];
    que.push((node){a,0});
    while(!que.empty()){
        u = que.front();
        que.pop();
        if(u.id == b) break;
        //上
        int x = u.id + k[u.id];
        if(x <= n && !vis[x]){
            que.push((node){x,u.s+1});
            vis[x] = 1;
        }
        //下
        int y = u.id - k[u.id];
        if(y >= 1 && !vis[y]){
            que.push((node){y,u.s+1});
            vis[y] = 1;
        }
    }
    if(u.id == b) cout << u.s;
        else cout << -1;
    return 0;
}