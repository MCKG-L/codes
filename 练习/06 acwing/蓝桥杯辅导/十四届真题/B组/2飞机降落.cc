#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 20;
typedef pair<int,int> PII;
vector<array<int,3>> p;
int n;
bool st[N];
bool dfs(int u,int k){
    if(u >= n){
        return true;
    }
    for(int i=0;i<n;i++){
        auto [t,d,l] = p[i];
        if(st[i]) continue;
        if(t + d >= k){
            st[i] = 1;
            if(dfs(u+1,max(k,t)+l)) return true;
            st[i] = 0;
        }
    }
    return false;
}
void solve(){
    p.clear();
    memset(st,false,sizeof st);
    cin >> n;
    for(int i=0;i<n;i++){
        int t,d,l;
        cin >> t >> d >> l;
        p.push_back({t,d,l});
    }
    if(dfs(0,0)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}