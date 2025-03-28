#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int x,y;
    cin >> x >> y;
    if(x == y){
        cout << 0 << endl;
        return;
    }
    if(x > y){
        int cnt = 0;
        while(x % 6 == 0){
            x /= 6;cnt ++;
            if(x == y || x < y) break;
        }
        while(x < y){
            x *= 5;cnt ++;
        }
        if(x == y){
            cout << cnt << endl;
        }else{
            cout << -1 << endl;
        }
    }else{
        int cnt = 0;
        while(x < y){
            x *= 5;cnt ++;
        }
        if(x != y){
            cout << -1 << endl;
        }else{
            cout << cnt << endl;
        }
    }
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}