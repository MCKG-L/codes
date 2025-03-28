#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int v[N];
int n,c;
void solve(){
    cin >> n >> c;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        v[i] = x + i;
    }
    sort(v+1,v+n+1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(c >= v[i]){
            ans ++;
            c -= v[i];
        }else{
            break;
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}