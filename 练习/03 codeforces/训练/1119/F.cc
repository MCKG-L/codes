#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n,q;
    cin >> n >> q;
    for(int i=1;i<n;i++){
        cout << i << ' ' << i + 1 << endl;
    }
    int lst = n - 1;
    while(q--){
        int x;cin >> x;
        if(lst == x){
            cout << -1 << ' ' << -1 << ' ' << -1 << endl;
        }else{
            cout << n << ' ' << lst << ' ' << x << endl;
            lst = x;
        }
    }
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}