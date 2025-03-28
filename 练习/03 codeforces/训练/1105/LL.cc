#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
typedef pair<string,string> PSS;
const int N = 2e5 + 110;
int n,m;
struct DSU{
    std::vector<int> f,siz;
    DSU(int n): f(n),siz(n,1){std::iota(f.begin(),f.end(),0);}
    int find(int x){
        while(f[x] != x) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int a,int b){return find(a) == find(b);}
    void unite(int a,int b){
        a = find(a);b = find(b);
        if(a == b) return;
        siz[a] += siz[b];
        f[b] = a;
    }
    int size(int x) {return siz[find(x)];}
};
void trans(string &s){
    for (auto & i : s) i = tolower(i);

}
void solve(){
    cin >> n >> m;
    vector<PSS> p(n);
    for(int i=0;i<n;i++){
        string name,city;
        cin >> name >> city;
        trans(name);
        // cout << name << ' ' << city << endl;
        p[i] = {name,city};
    }
    // cout << "1" << endl;
    DSU dsu(n+10);
    map<string,vector<int>> mp;
    for(int i=0;i<n;i++){
        string c = p[i].second;
        mp[c].push_back(i+1);
    }
    for(auto [x,y] : mp){
        int id = y[0];
        // for(auto s : y) cout << s << ' ';
        // cout << endl;
        for(auto s : y) 
        dsu.unite(id,s);
    }
    vector<map<string,int>> mp1(n+1);
    for(int i=0;i<n;i++){
        string s = p[i].first;
        string t;
        for(int j=0;j<s.size();j++){
            if(s[j] != '_') t += s[j];
            else{
                mp1[i+1][t] ++;
                t = "";
            }
        }
        mp1[i+1][t] ++;
    }
    mp.clear();
    for(int i=0;i<m;i++){
        string s;cin >> s;
        int len = s.size();
        for(int j=0;j<n;j++){
            string name = p[j].first;
            // if(name.find(s) != string::npos){
            //     int pos = name.find(s);
            //     int l = name.size();
            //     if(pos > 0 && name[pos-1] != '_') continue;
            //     if(pos + len < l && name[pos+len] != '_') continue;
            //     mp[s].push_back(j+1);
            // }
            if(mp1[j+1].count(s)) mp[s].push_back(j+1);
        }
    }
    for(auto [x,y] : mp){
        int id = y[0];
        for(auto s : y) dsu.unite(id,s);
    }
    for(int i=1;i<=n;i++){
        cout << dsu.size(i)-1 << endl;
    }
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}