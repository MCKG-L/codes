#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
    }
    if(n & 1){
        cout << 4 << '\n';
        for(int i=0;i<2;i++) cout << 1 << ' ' << n - 1 << endl;
        for(int i=0;i<2;i++) cout << n -1 << ' ' << n << endl;
    }else{
        cout << 2 << endl;
        for(int i=0;i<2;i++) cout << 1 << ' ' << n << endl;
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