#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
//建立超级源点 最长路 
const int N = 750;
int e[N],ne[N],w[N],h[N],idx;
int dis[N];
bool st[N];
int cnt[N];
int d,p,c,f,ans;
void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
bool spfa(){
    memset(dis,-0x3f,sizeof dis);
    queue<int> q;
    q.push(0);
    dis[0] = 0;st[0] = 0;
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = 0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] < dis[t] + d - w[i]){
                dis[j] = dis[t] + d - w[i];
                if(cnt[j] > c) return true;
                if(!st[j]){
                    cnt[j]++;
                    st[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    for(int i=1;i<=c;i++){
        ans = max(ans,dis[i]);
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
        add(a,b,0);
    }
    while(f--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    for(int i=1;i<=c;i++) add(0,i,0);
    if(spfa()) puts("orz");
    else cout << ans << endl;
    return 0;
}