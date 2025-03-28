#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e5 + 10;
int n,M,q;
vector<map<int,pair<int,int>>> mp(N);
int cnt = 1e6;
vector<int> id(1e6);
int cal(int x){
    return (x / n) % M;
}
void solve(){
    cin >> n >> M >> q;
    vector<pair<int,int>> ans;
    while(q --){
        int op,x;
        cin >> op >> x;
        auto &ver = mp[cal(x)];
        auto it = ver.find(id[x]);
        if(!id[x] || it == ver.end()){ //不在cache中
            ans.push_back({0,x});
            id[x] = --cnt;
            ver[id[x]] = {x,op};
            if(ver.size() > n){
                auto c = prev(ver.end());
                if(c->second.second == 1){
                    ans.push_back({1,c->second.first});
                }
                ver.erase(c);
            }
        }else{ //在cache中
            id[x] = -- cnt;//更新
            ver[id[x]] = it->second;
            if(op == 1) ver[id[x]].second = 1;
            ver.erase(it);
        }
    }
    for(auto t : ans){
        cout << t.first << ' ' << t.second << endl;
    }
}
#define LOCAL
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    #ifdef LOCAl
    
    #endif
    // cin >> T;
    while(T --) solve();
    return 0;
}