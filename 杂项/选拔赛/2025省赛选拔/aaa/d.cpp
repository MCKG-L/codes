#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
const int N = 2e5 + 10,mod = 1e9 + 7,inf = 1e18;
int cal(int x,int y,int m){
    int t = x;
    while(t <= y && t % m != 0) t ++;
    if(t > y) return 0;
    return (y - t) / m + 1;
}
void solve(){
    int x,y;
    cin >> x >> y;
    int cnt1 = cal(x,y,4);
    int cnt2 = cal(x,y,100);
    int cnt3 = cal(x,y,400);
    cout << cnt1 + cnt3 - cnt2 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}