#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;

void solve(){
    string a,b;
    cin >> a >> b;
    int n = a.size();
    for(int i=0;i<n-1;i++){
        if(a[i] == b[i] && a[i] == '0' && a[i+1] == b[i+1] && a[i+1] == '1'){
            cout << "YES" << endl;
            return;
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