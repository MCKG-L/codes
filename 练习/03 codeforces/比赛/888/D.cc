#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i=1;i<n;i++) cin >> a[i];
    int sum = 0,k = 0;
    vector<bool> st(n+1,false);
    for(int i=1;i<n;i++){
        int x = a[i] - a[i-1];
        if(x > n || st[x]){
            if(k != 0){
                cout << "NO" << endl;
                return;
            }
            k = x;
        }else{
            st[x] = 1;
            sum += x;
        }
    }
    if(k == 0){
        for(int i=1;i<=n;i++){
            if(st[i] == 0) k = i;
        }
    }
    if(k + sum == n*(n+1)/2) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}