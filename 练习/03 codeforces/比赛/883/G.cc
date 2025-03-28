#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1100,M = 2e6,INF = 0x3f3f3f3f;
/*
有n种症状，根据各种症状的存在情况，一共有2^n中状态，把每一种状态看成一个节点
对于一种药，可以让这2^n中状态转移到相应的另外一种状态，所需代价就是服药次数k
有m种药，一共会有2^n*m条边
*/
int n = 5,m;
int h[N],e[M],ne[M],w[M],idx;
void add(int a,int b,int c){
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
int cal(string s){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = ans * 2 + s[i]-'0';
    }
    return ans;
}
void Dijkstra(int s){
    vector<int> dis(1<<n,INF);
    vector<bool> st(1<<n,false);
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,s});
    dis[s] = 0;
    while(heap.size()){
        auto [d,k] = heap.top();heap.pop();
        if(st[k]) continue;
        st[k] = true;
        for(int i=h[k];~i;i=ne[i]){
            int j = e[i];
            if(dis[j] > d + w[i]){
                dis[j] = d + w[i];
                heap.push({dis[j],j});
            }
        }
    }
    if(dis[0] != 0x3f3f3f3f) cout << dis[0] << endl;
    else cout << -1 << endl;
}
void solve(){
    cin >> n >> m;
    idx = 0;
    for(int i=0;i<(1<<n);i++) h[i] = -1;
    string s;cin >> s;
    int st = cal(s);
    while(m--){
        string s1,s2;
        int x;cin >> x;
        cin >> s1 >> s2;
        int u = cal(s1),v = cal(s2);
        for(int i=0;i<(1<<n);i++){
            int t = i & (~u) | v;//状态i在药物u的作用后一定会变成状态t
            add(i,t,x);
        }
    }
    //Dijkstra
    Dijkstra(st);
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    // cout << cal("11101") << endl;
    while(T--) solve();
    return 0;
}