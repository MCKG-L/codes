    #include <bits/stdc++.h>
    #define endl '\n'
    using namespace std;
    typedef pair<int,int> PII;
    const int N = 1e5 + 10;
    vector<vector<int>> a(N);
    int color[N],fa[N];
    int n,m;
    int find(int x){
        while(x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    void dfs(int u,int f){
        for(auto v : a[u]){
            if(v == f) continue;
            if(color[v] == color[u]) fa[find(u)] = find(v);
            dfs(v,u);
        }
    }
    void solve(){
        cin >> n >> m;
        string s;cin >> s;
        for(int i=0;i<n;i++){
            color[i+1] = s[i] == 'H' ? 0 : 1;
            fa[i+1] = i + 1;
        }
        for(int i=0;i<n-1;i++){
            int u,v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        dfs(1,0);
        while(m --){
            int u,v;
            cin >> u >> v;
            string c;cin >> c;
            int _color = c == "H" ? 0 : 1;
            if(find(u) == find(v) && _color != color[u]){
                cout << 0;
            }else{
                cout << 1;
            }
        }
        cout << endl;
    }
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T = 1;
        // cin >> T;
        while(T --) solve();
        return 0;
    }