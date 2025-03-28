#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int cnt[10];
void init(){
    for(int x=0;x<=9;x++){
        for(int i=0;i<=x;i++){
            for(int j=0;j<=x;j++){
                if(i+j<=x) cnt[x] ++;
            }
        }
    }
}
void solve(){
    int n;cin >> n;
    int ans = 1;
    while(n) ans *= cnt[n%10],n /= 10;
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--) solve();
    return 0;
}