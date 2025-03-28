#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
char s[N];
map<char,int> mp;
void solve(){
    mp.clear();
    int n;cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++){
        cin >> s[i];
        mp[s[i]]++;
        cnt = max(cnt,mp[s[i]]);
    }
    if(cnt > n / 2 || n & 1){
        cout << -1 << endl;
        return;
    }
    cnt = 0;
    mp.clear();
    int max_n = 0;
    for(int i=0;i<n/2;i++){
        if(s[i] == s[n-i-1]){
            cnt ++;
            mp[s[i]]++;
            max_n = max(max_n,mp[s[i]]);
        }
    }
    int ans = (int)ceil(1.0*cnt/2);
    cout << max(ans,max_n) << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}