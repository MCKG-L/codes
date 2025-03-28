#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int l[N],r[N];
int n;
char s[N];
void solve(){
    map<int,int> mp;
    cin >> n >> s + 1;
    r[n+1] = 0;
    for(int i=1;i<=n;i++){
        l[i] = l[i-1];
        if(!mp.count(s[i])) l[i] ++;
        mp[s[i]] ++;
    }
    mp.clear();
    for(int i=n;i>=1;i--){
        r[i] = r[i+1];
        if(!mp.count(s[i])) r[i] ++;
        mp[s[i]] ++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,l[i]+r[i+1]);
    }
    cout << ans << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}