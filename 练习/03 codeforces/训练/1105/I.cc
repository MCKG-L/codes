#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    // int n;cin >> n;
    int st[10] = {};
    for(int i=0;i<3;i++){
        int x;cin >> x;
        st[x] = 1;
    }
    int a0,a1,b0,b1;
    cin >> a0 >> a1 >> b0 >> b1;
    if(a0 == b0){
        int cnt = 0;
        for(int i=a1;i<b1;i++){
            if(!st[i]) cnt ++;
        }
        cout << cnt << endl;
        return;
    }
    int d = b0 - a0 - 1;
    int cnt = d * 4;
    for(int i=a1;i<=7;i++){
        if(!st[i]) cnt ++;
    }
    for(int i=1;i<b1;i++){
        if(!st[i]) cnt ++;
    }
    cout << cnt << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}