#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int cnt[N];
void solve(){
    int q,n,m;
    cin >> q >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;cin >> x;
            cnt[x] ++;
        }
    }
    priority_queue<int> que;
    for(int i=1;i<=q;i++){
        if(cnt[i] > 0) que.push(cnt[i]);
    }
    while(que.size() > 1){
        int k1 = que.top();que.pop();
        int k2 = que.top();que.pop();
        k1 --;if(k1)que.push(k1);
        k2 --;if(k2)que.push(k2);
    }
    if(que.size()){
        cout << que.top() << endl;
    }else{
        cout << 0 << endl;
    }
}
signed main()
{
    int t = 1;
    // cin >> t;
    while(t--) solve();
}