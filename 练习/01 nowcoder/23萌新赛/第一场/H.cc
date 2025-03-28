#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
const int N = 3e6 + 10;
int h[N],ne[N],e[N],w[N],idx;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n,m;
char a[3010][3010];
int dis[N];
bool st[N];
int cal(int x,int y){
    //将二维坐标映射到一个单点上
    return (x - 1) * m + y;
}
void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++;
}
void Dijkstra(){
    memset(dis,0x3f,sizeof dis);
    dis[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(heap.size()){
        PII t = heap.top();heap.pop();
        int k = t.second,d = t.first;
        if(st[k]) continue;
        st[k] = true;
        for(int i=h[k];~i;i=ne[i]){
            int j =e[i];
            if(dis[j] > d + w[i]){
                dis[j] = d + w[i];
                heap.push({dis[j],j});
            }
        }
    }
}
int main()
{
    memset(h,-1,sizeof h);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    //根据题意建图，然后跑最短路即可
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //遇到炮弹先不建边，因为必须乘坐炮弹，需要额外建特殊边
            if(a[i][j] == '.'){
                for(int k=0;k<4;k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x < 1 || x > n || y < 1 || y > m || a[x][y]=='#') continue;
                    add(cal(i,j),cal(x,y),1);
                }
            }
        }
    }
    int q;cin >> q;
    while(q--){
        int x,y,d;
        cin >> x >> y >> d;
        for(int k=0;k<4;k++){
            int nx = x + dx[k]*d;
            int ny = y + dy[k]*d;
            //炮弹可以穿墙，只要终点不是墙并且不越界都可以到达
            //中间不可以停下，必须选择使用炮弹
            if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '#') continue;
            add(cal(x,y),cal(nx,ny),0);
        }
    }
    Dijkstra();
    if(dis[cal(n,m)] != 0x3f3f3f3f) cout << dis[cal(n,m)] << endl;
    else cout << -1 << endl;
    return 0;
}