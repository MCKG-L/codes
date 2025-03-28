/*
spfa + 判断负环
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e3+10,M = 1e4+10;
int e[M],h[N],w[M],ne[M],idx;
int dis[N],cnt[N];
bool st[N];
int n,m;
void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
bool spfa(int s){
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);
    memset(dis,0x3f,sizeof dis);
    dis[s] = 0;st[s] = 1;
    queue<int> q;
    q.push(s);
    while(q.size()){
        int t = q.front();q.pop();
        st[t] = 0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > dis[t] + w[i]){
                dis[j] = dis[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j]) q.push(j),st[j] = true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,-c);
    }
    bool flag = spfa(1);
    if(flag){
        cout << "Forever love" << endl;
        return 0;
    }
    int ans = dis[n];
    flag = spfa(n);//从n开始再跑一遍
    if(flag){
        cout << "Forever love" << endl;
        return 0;
    }
    ans = min(ans,dis[1]);
    cout << ans << endl;
    return 0;
}