#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    double ans = 0;
    for(int i=0;i<n;i++){
        map<int,int> mp;
        int cnt = 0;
        for(int j=i;j<n;j++){
            cnt += mp[s[j]-'a'];
            mp[s[j]-'a']++;
            ans = max(1.0*cnt/(j-i+1),ans);
        }
    }
    printf("%.6f\n",ans);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}