#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
const int N = 110;
int a[N];
void solve(){
    int n;cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int ans = 0;
    int s = 0;
    for(int i=0;i<n;i++){
        if(a[i] != 0){
            ans = max(ans,s);
            s = 0;
        }else s ++;
    }
    ans = max(ans,s);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}