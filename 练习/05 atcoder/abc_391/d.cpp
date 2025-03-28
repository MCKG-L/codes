#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
struct Node{
    int x,y,id;
    bool operator < (const Node p)const{
        return y > p.y;
    }
};
void solve(){
    int n,m;
    cin >> n >> m;
    vector<priority_queue<Node>> a(n + 10);
    for(int i=1;i<=n;i++){
        int x,y;
        cin >> x >> y;
        a[x].push({x,y,i});
    }
    vector<int> ans(n + 10,-1);
    int M = -1;
    while(1){
        // int M = -1;
        vector<int> ids;
        bool ok = 1;
        for(int i=1;i<=m;i++){
            if(a[i].size() > 0){
                auto [x,y,id] = a[i].top();
                a[i].pop();
                M = max(M,y);
                ids.push_back(id);
            }else{
                ok = 0;
                break;
            }
        }
        if(ok == 0) break;
        for(auto id : ids){
            ans[id] = M;
        }
    }
    int q;cin >> q;
    while(q --){
        int t,id;
        cin >> t >> id;
        if(ans[id] == -1){
            cout << "Yes" << endl;
        }else{
            cout << (t >= ans[id] ? "No" : "Yes") << endl;
        }
    }
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