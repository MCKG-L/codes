#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n;cin >> n;
    // int ans = 2e9;
    int lst = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x <= lst) lst = lst + 1;
        else{
            if(x == lst + 1) lst = x + 1;
            else lst ++;
        }
    }
    cout << lst << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}