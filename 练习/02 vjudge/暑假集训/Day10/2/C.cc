#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 110;
map<string,int> mp;
string reverse(string s){
    reverse(s.begin(),s.end());
    return s;
}
void solve(){
    int n;cin >> n;
    for(int i=0;i<n;i++){
        string s;cin >> s;
        if(!mp.count(s) && !mp.count(reverse(s))) mp[s] ++;
    }
    cout << mp.size() << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}