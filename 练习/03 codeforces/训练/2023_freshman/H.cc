#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e6 + 10;
int f[N];
void init(){
    f[1] = 0;
    for(int i=2;i<N;i++){
        f[i] = f[i-1];
        for(int j=30;j>=0;j--){
            int dx = (i - 1) >> j & 1ll;
            int dy = i >> j & 1ll;
            if(dx != dy) f[i] ++;
        }
    }
}
void solve(){
    int x,y;
    cin >> x >> y;
    cout << f[x + y] - f[x] << endl;
}
signed main()
{
    IOS;int T = 1;init();
    cin >> T;
    while(T--) solve();
    return 0;
}