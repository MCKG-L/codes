#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int n,m;
int v[N];
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        v[i] = x + i;
    }
    sort(v+1,v+1+n);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(m >= v[i]){
            ans ++;
            m -= v[i];
        }else{
            break;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}