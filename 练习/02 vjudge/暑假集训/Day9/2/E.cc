#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int a[N],n;
char s[N];
vector<vector<int>> L(N,vector<int>(3,0)),R(N,vector<int>(3,0));
int mex(int a,int b,int c){
    for(int i=0;i<3;i++){
        if(a != i && b != i && c != i) return i;
    }
    return 3;
}
int cnt(int x){
    int ans = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans += mex(i,j,a[x])*L[x][i]*R[x][j];
        }
    }
    return ans;
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> s[i];
    for(int i=1;i<=n;i++){
        L[i] = L[i-1];
        if(s[i] == 'M') L[i][a[i]] ++;
    }
    for(int i=n;i>=1;i--){
        R[i] = R[i+1];
        if(s[i] == 'X') R[i][a[i]] ++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(s[i] != 'E') continue;
        ans += cnt(i);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}