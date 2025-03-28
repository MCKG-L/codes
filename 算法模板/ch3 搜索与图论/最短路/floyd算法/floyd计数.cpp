/*
跑一边floyd的同时 记录任意两点最小路径的条数
还可以算出任意两点的最短路径中经过某一个结点的最短路条数
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 110,M = 4510;
long long dis[N][N];
long long cnt[N][N];
double ans[N];
int n,m;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    cnt[i][j] = cnt[i][k] * cnt[k][j];
                }else if(dis[i][j] == dis[i][k] + dis[k][j]){
                    cnt[i][j] += cnt[i][k] * cnt[k][j];
                }
            }
        }
    }
}
void solve(){//计算经过k的最短路径条数
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(k == i) continue;
            for(int j=1;j<=n;j++){
                if(j == k || j == i) continue;
                if(dis[i][k] + dis[k][j] == dis[i][j]){
                    long long sum = cnt[i][k] * cnt[k][j];
                    ans[k] += 1.0 * sum / cnt[i][j];
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    memset(dis,0x3f,sizeof dis);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        dis[a][b] = dis[b][a] = c;
        cnt[a][b] = cnt[b][a] = 1;
    }
    floyd();solve();
    for(int i=1;i<=n;i++){
        printf("%.3f\n",ans[i]);
    }
    return 0;
}