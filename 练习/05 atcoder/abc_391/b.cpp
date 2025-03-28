#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> cnt(n+1,1);
    vector<int> pos(n + 1);
    iota(pos.begin(),pos.end(),0);
    int ans = 0;
    for(int i=0;i<m;i++){
        int op;cin >> op;
        if(op == 1){
            int a,b;
            cin >> a >> b;
            cnt[pos[a]] --,cnt[b] ++;
            if(pos[a] == b) continue;
            if(cnt[pos[a]] == 1) ans --;
            if(cnt[b] == 2) ans ++;
            pos[a] = b;
        }else{
            cout << ans << endl;
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