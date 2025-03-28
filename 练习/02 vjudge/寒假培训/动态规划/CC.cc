#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n,m,a[N];
int mp[N][N];
// int process(int i,int j){
//     if(mp[i][j] != -1) return mp[i][j];
//     int ans = 0;
//     if(j == 0) ans = 1;
//     else if(i == n + 1) ans = 0;
//     for(int k=0;k<=a[i] && j>=k;k++){
//         ans += process(i+1,j-k);
//     }
//     mp[i][j] = ans;
//     return ans;
// }
int solve(){
    for(int i=1;i<=n+1;i++) mp[i][0] = 1;
    for(int i=n;i>=1;i--){
        for(int j=0;j<=m;j++){
            int ans = 0;
            for(int k=0;k<=j&&k<=a[i];k++){
                ans += mp[i+1][j-k];
            }
            mp[i][j] = ans % 1000007;
        }
    }
    // for(int i=1;i<=n+1;i++){
    //     for(int j=0;j<=m;j++){
    //         mp[i][j] = -1;
    //     }
    // }
    cout << "mp: " << endl;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m;j++){
            cout << mp[i][j] << " \n"[j == m];
        }
    }
    return mp[1][m];
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    cout << solve();
}