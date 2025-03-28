#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int n;cin >> n;
    if(n < 7){
        cout << "NO" << endl;
        return;
    }
    for(int k=2;k<1000;k++){
        int s = 0;
        for(int i=0;i<100;i++){
            s = s * k + 1;
            if(s == n){
                if(i >= 2) cout << "YES" << endl;
                else cout << "NO" << endl;
                return;
            }
            if(s > n) break;
        }
    }
    cout << "NO" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}