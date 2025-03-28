#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 5010;
int a[N],h[N];
int n,m;
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> h[i];
    vector<PII> p;
    for(int i=0;i<m;i++){
        int l,r;cin >> l >> r;
        p.push_back({l,r});
    }
    for(int i=0;i<m;i++){
        int l = p[i].first,r = p[i].second;
        bool f = 0;
        for(int i=l;i<=r;i++){
            h[i] --;
            if(h[i] < 0){
                f = 1;break;
            }
        }
        if(f){
            cout << i << endl;
            return;
        }
    }
    cout << m << endl;
}
signed main()
{
    int t = 1;
    // cin >> t;
    while(t--) solve();
}