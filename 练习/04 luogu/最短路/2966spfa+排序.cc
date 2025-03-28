#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;
const int N = 300,INF = 0x3f3f3f3f;
int ans[N][N],dis[N][N];
struct node{
    int v,p;
}a[N];
int n,m,q;
bool cmp(node p1,node p2)
{
    return p1.v < p2.v;
}
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int kk=a[k].p,ii=a[i].p,jj=a[j].p;
                dis[ii][jj] = min(dis[ii][jj],dis[ii][kk]+dis[kk][jj]);
                ans[ii][jj] = min(ans[ii][jj],dis[ii][jj]+max(a[i].v,max(a[j].v,a[k].v)));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    memset(ans,0x3f,sizeof ans);
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        int v;cin >> v;
        a[i] = {v,i};
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b],c);
        dis[b][a] = min(dis[b][a],c);
    }
    floyd();
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << ans[a][b] << endl;
    }
    return 0;
}