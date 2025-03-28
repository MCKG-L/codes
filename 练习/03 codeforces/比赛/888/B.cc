#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    // vector<pair<int,int>> p;
    vector<int> a,b;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        a.push_back(x);
        b.push_back(x);
    }
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        int x = b[i] & 1;
        int y = a[i] & 1;
        if(x ^ y){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}