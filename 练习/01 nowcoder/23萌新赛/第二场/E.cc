#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;
const int N = 1e6 + 10;
int a[N],b[N];//差分数组
int n;
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        b[i] = x;
        if(x > 0){
            int l = max(i-x,1);
            int r = min(i+x,n);
            a[l] ++;
            a[r+1]--;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        a[i] += a[i-1];
    }
    for(int i=1;i<=n;i++){
        if(b[i] > 0) a[i] --;
        if(a[i] > 0) ans ++;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}