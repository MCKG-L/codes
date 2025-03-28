#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
using i128 = __int128;
void solve(){
    int x;cin >> x;
    int cnt = min(1,(x+2)/2);
    i128 ans = (i128)cnt * (x - 2 * cnt) * (x - 2 * cnt - 1) / 2;
    auto out = [&](auto out,i128 ans) -> void{
        if(ans < 0){
            cout << "-";
            x = -x;
        }else{
            out(out,x/10);
        }
        cout << x % 10;
    };
    out(out,ans);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}