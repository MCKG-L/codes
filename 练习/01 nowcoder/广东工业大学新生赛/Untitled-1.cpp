#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 10,M = 2 * N;
void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    int d = abs(b-c);
    if(d % 2 == 0 && d / 2 <= a){
        cout << 1 << ' ';
    }else cout << 0 << ' ';
    d = abs(a-c);
    if(d % 2 == 0 && d / 2 <= b){
        cout << 1 << ' ';
    } else cout << 0 << ' ';
    d = abs(a-b);
    if(d % 2 == 0 && d / 2 <= c){
        // ans[2] = 1;
        cout << 1 << ' ';
    } else cout << 0 << ' ';
    // for(int i=0;i<3;i++){
    //     if(ans[i] == 1) cout << 1 << ' ';
    //     else cout << 0 << ' ';
    // }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}