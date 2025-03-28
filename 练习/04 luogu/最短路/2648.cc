#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 710;
int e[N],ne[N],w[N],h[N],idx;
int dis[N],cnt[N];
int d,p,c,f,ans;
bool st[N];
void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
bool spfa(){
    memset(dis,0x3f,sizeof dis);
    queue<int> q;
    q.push(0);dis[0] = 0;
    st[0] = 1;
    while(q.size()){
        int t = q.front();
        q.pop();st[t] = 0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > dis[t] + w[i]){
                dis[j] = dis[t] + w[i];
                if(cnt[j] > c) return true;
                if(!st[j]){
                    q.push(j);
                    cnt[j]++;
                    st[j] = 1;//有重边
                }
            }
        }
    }
    ans = 0x3f3f3f3f;
    for(int i=1;i<=c;i++){
        ans = min(ans,dis[i]);
    }
    return false;
}
int main()
{
    cin >> d >> p >> c >> f;
    memset(h,-1,sizeof h);
    while(p--){
        int a,b;
        cin >> a >> b;
        add(a,b,0-d);
    }
    while(f--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c-d);
    }
    //建立超级源点 只需要跑一遍spfa
    for(int i=1;i<=c;i++){
        add(0,i,0-d);
    }
    //有负环 则输出orz
    if(spfa()) puts("orz");
    else cout << -ans << endl;
    return 0;
}