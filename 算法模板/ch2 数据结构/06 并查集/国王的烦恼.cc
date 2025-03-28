#include <iostream>
#include <algorithm>
using namespace std;
/*
把抗议的发生条件等效为连通块数目的改变
用并查集维护岛屿之间的连接情况
*/
const int N = 10010,M = 100010;
struct Bridge{
    int x,y;
    int day;
    Bridge(){};
    Bridge(int a,int b,int c):x(a),y(b),day(c){};
}bridge[M];
int p[N];//n个小岛的父元素
bool cmp(Bridge p1,Bridge p2){
    return p1.day > p2.day;
}
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
bool unite(int a,int b){
    if(find(a) != find(b)){
        p[find(a)] = find(b);
        return true;
    }else return false;
}
int main()
{
    int a,b,m,n,t;
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=1;i<=m;i++){
        cin >> a >> b >> t;
        bridge[i] = Bridge(a,b,t);
    }
    sort(bridge+1,bridge+m+1,cmp);
    int ans = 0,lastday = 0;//记录上次抗议的时间，同一天的抗议只记录一次
    for(int i=1;i<=m;i++){
        bool flag = unite(bridge[i].x,bridge[i].y);//连通块数发生改变
        if(flag && bridge[i].day != lastday){
            ans ++;
            lastday = bridge[i].day;
        }
    }
    cout << ans << endl;
    return 0;
}