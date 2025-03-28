#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n,k;
    cin >> n >> k;
    string s;cin >> s;
    map<char,int> mp;
    int sum = 0;
    for(auto i : s){
        mp[i] ++;
    }
    for(auto [x,t] : mp){
        if(t >= 2) sum += t/2*2;
    }
    n -= k;
    if(sum >= n){
        cout << "YES" << endl;
        return;
    }
    if((n & 1) && sum == n - 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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