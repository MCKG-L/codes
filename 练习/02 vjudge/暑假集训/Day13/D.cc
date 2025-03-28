#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10,M = 2*N;
int h[N],ne[M],e[M],idx;
int ind[N];
bool st[N];
int n,p;
vector<int> sa;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
stack<int> sk;
void dfs(int u){
    sk.push(u);st[u] = 1;
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        if(st[j]) continue;
        dfs(j);
    }
}
void solve(){
    cin >> n;
    sa.clear();
    memset(st,0,n+2);
    memset(h,-1,(n+2)*4);
    memset(ind,0,(n+2)*4);
    idx = 0;
    for(int i=1;i<=n;i++){
        int u;cin >> u;
        if(u == i) p = u;
        else add(i,u);
        ind[u] ++;
    }
    if(n == 1){
        cout << 1 << '\n' << 1 << '\n' << 1 << endl;
        cout << endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(ind[i] == 0) sa.push_back(i);
    }
    cout << sa.size() << endl;
    for(auto it : sa){
        // cout << "---" << it << endl;
        dfs(it);
        cout << sk.size() << endl;
        while(sk.size()){
            cout << sk.top() << ' ';
            sk.pop();
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}