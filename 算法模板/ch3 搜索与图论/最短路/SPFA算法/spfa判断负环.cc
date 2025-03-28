#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
/*
图中可能存在重边和自环以及负权 判断图中是否含有负环
*/
const int N = 100010;
int n,m;
int e[N],h[N],ne[N],w[N],idx;
int dis[N],cnt[N];
bool st[N];
void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int spfa(){
    queue<int> q;
    //判断负环 先把所有起点放入队列中 因为从某一个起点可能不能到达某一个负环
    for(int i=1;i<=n;i++){
        st[i] = 1;
        q.push(i);
    }
    while(q.size()){
        //这里不需要初始化距离 因为如果存在负环，会陷入死循环，直到cnt[j] >= n 
        //可以初始化距离，这样如果不存在负环，也可以正常求出最短路
        int t = q.front();q.pop();
        st[t] = 0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > dis[t] + w[i]){
                dis[j] = dis[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j]) q.push(j),st[j] = 1;
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof(h));
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    if(spfa()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}