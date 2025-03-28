#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    int cnt = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] % 2 == 0) cnt ++;
    }
    int ans = 1e9;
    if(k == 4){
        if(cnt >= 2) ans = 0;
        else if(cnt >= 1) ans = 1;
        else ans = 2;
    }
    for(int i=0;i<n;i++){
        int x = a[i];
        int s = 0;
        for(int j=0;j<=5;j++){
            if((x + j) % k == 0){
                s = j;break;
            }
        }
        ans = min(ans,s);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}