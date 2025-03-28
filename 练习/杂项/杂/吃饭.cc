#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    int ans = 1e9 + 10;
    for(int i=0;i<n;i++){
        int k,x,y;
        cin >> k >> x >> y;
        int kk[k];
        for(int j=0;j<k;j++) cin >> kk[j];
        if(ans == 0) continue;
        int sum = 0;
        for(int j=0;j<k;j++){
            int ki = kk[j];
            if(ki >= a && ki >= x) sum = max(ki-b-y,0);
            else if(ki >= a) sum  = ki - b;
            else if(ki >= x) sum = ki - y;
            else sum = ki;
            ans = min(ans,sum);
            if(sum == 0) break;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}