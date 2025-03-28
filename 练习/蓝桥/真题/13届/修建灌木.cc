#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using ll = long long;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        cout << max({i,(n-i)*2,n-i+1,(i-1)*2}) << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}