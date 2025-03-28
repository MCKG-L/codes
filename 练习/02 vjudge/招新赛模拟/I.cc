#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n,k;
void solve(){
    cin >> n  >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    int cnt = 1;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(a[i] == cnt){
            cnt ++;
        }
    }
    // cout << cnt-1 << endl;
    ans = ceil(1.0*(n-cnt+1)/k);
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}