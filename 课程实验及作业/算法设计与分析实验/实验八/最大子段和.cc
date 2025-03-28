#include <iostream>
#define endl '\n'
using namespace std;
const int N = 2e5  + 10;
int dp[N],a[N],n;
int path[N];
void getPath(int i){
    if(path[i] == i){
        cout << a[i] << ' ';
        return;
    }
    getPath(path[i]);
    cout << a[i] << ' ';
}
void solve(){
    cin >> n;   
    for(int i=1;i<=n;i++) cin >> a[i];
    dp[0] = -2e9;
    for(int i=1;i<=n;i++){
        if(dp[i-1] + a[i] > a[i]){
            dp[i] = dp[i-1] + a[i];
            path[i] = i - 1;
        }else{
            dp[i] = a[i];
            path[i] = i;
        }
    }
    int ans = -1e9,st = -1;
    for(int i=1;i<=n;i++){
        if(dp[i] > ans){
            ans = dp[i];
            st = i;
        }
    }
    cout << ans << endl;
    cout << endl;
    getPath(st);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}