#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1e5 + 10;
/*
求最小字典序的拓扑序
*/
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    vector<int> ind(n + 1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        ind[v] ++;
    }
    vector<int> st(n + 1);
    vector<int> v;
    auto topsort = [&]()->void{
        priority_queue<int,vector<int>,greater<int>> heap;
        for(int i=1;i<=n;i++){
            if(ind[i] == 0){
                st[i] = 1;
                heap.push(i);
            }
        }
        while(heap.size()){
            int ver = heap.top();heap.pop();
            v.push_back(ver);
            for(auto x : a[ver]){
                if(--ind[x] == 0){
                    st[x] = 1;
                    heap.push(x);
                }
            }
        }
    };
    topsort();
    for(auto x : v){
        cerr << x << ' ';
    }
    int i = 1;
    for(auto x : v){
        while(i <= n && !st[i] && i < x){
            cout << i << ' ';
            i ++;
        }
        cout << x << ' ';
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}
