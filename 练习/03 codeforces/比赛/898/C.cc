#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
char s[11][11];
int f(int i,int j){
    int a = min(i+1,10-i);
    int b = min(j+1,10-j);
    return min(a,b);
}
void solve(){
    int ans = 0;
    for(int i=0;i<10;i++) cin >> s[i];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(s[i][j] == '.') continue;
            ans += f(i,j);
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}