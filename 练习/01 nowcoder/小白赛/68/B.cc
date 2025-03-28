#include <bits/stdc++.h>
using namespace std;
void solve(){
    int ans = 1e9 + 10;
    int n,a,b;
    cin >> n >> a >> b;
    for(int i=0;i<n;i++){
        int k,x,y;
        cin >> k >> x >> y;
        for(int j=0;j<k;j++){
            int ki;cin >> ki;
            int sum = 0;
            if(ki >= x && ki >= a){
                sum = max(0,ki-y-b);
            }else if(ki >= x){
                sum = max(0,ki-y);
            }else if(ki >= a){
                sum = max(0,ki-b);
            }else sum = ki;
            ans = min(ans,sum);
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}