#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std;
const int N = 2e5 + 1,M = 1e6 + 10;
unordered_map<int,int> mp;
int h[N],ne[M],e[M],idx;
int n,m;
bool st[N];
int p[N];
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    a = find(a),b = find(b);
    if(a != b) p[a] = b;
}
bool check(int a,int b){
    memset(st,false,sizeof st);
    queue<int> que;
    que.push(a);
    // st[a] = 1;
    while(que.size()){
        int t = que.front();que.pop();
        if(st[t]) continue;
        st[t] = 1;
        for(int i=h[t];~i;i=ne[i]){
            int j = e[i];
            // if(st[j]) continue;
            if(mp.count(j)){
                if(find(j) == find(mp[j])) return false;
            }
            if(!st[j]) que.push(j);
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i] = i;
    memset(h,-1,sizeof h);
    for(int i=0;i<n;i++){
        int u,v;cin >> u >> v;
        add(u,v),add(v,u);
        merge(u,v);
    }
    int k;cin >> k;
    while(k--){
        int x,y;
        cin >> x >> y;
        mp[x] = y;mp[y] = x;
        if(p[x] != p[y]) puts("YES");
        else puts("NO");
    }
    int q;cin >> q;
    while(q--){
        int a,b;cin >> a >> b;
        if(check(a,b) && check(b,a)) puts("Yes");
        else puts("No");
    }
    return 0;
}