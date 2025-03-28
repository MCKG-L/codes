#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
typedef pair<string,int> PSI;
const int N = 2e5 + 10;
map<PII,int> mp;
void solve(){
    mp.clear();
    int n;cin >> n;
    vector<pair<string,int>> a(n);
    for(int i=0;i<n;i++){
        string s;cin >> s;
        a[i] = {s,s.size()};
        // int sum = 0;
        // for(int j=0;j<s.size();j++) sum += s[j]-'0';
        // mp[{s.size(),sum}] ++;
    }
    int ans = 0;
    sort(a.begin(),a.end(),[&](PSI p1,PSI p2){
        return p1.second < p2.second;
    });
    for(int i=0;i<n;i++){
        string s = a[i].first;

        int len = s.size();
        int sum = 0;
        // cout << "s: " << s << endl;
        for(int j=0;j<len;j++) sum += s[j]-'0';
        for(int j=1;j<=5;j++){
            if((len+j) & 1) continue;
            if(j <= len){
                int k = (len - j) / 2;
                string ss = s.substr(0,k);
                int x = 0;
                for(int l=0;l<ss.size();l++) x += ss[l]-'0';
                // cout << "#: " << j << ' ' << sum-x*2 << ' ' << mp[{j,sum-x}] << ' ' << ss << endl;
                ans += mp[{j,sum-2*x}];
            }
        }
        reverse(s.begin(),s.end());
        for(int j=1;j<=5;j++){
            if((len+j) & 1) continue;
            if(j <= len){
                int k = (len - j) / 2;
                string ss = s.substr(0,k);
                int x = 0;
                for(int l=0;l<ss.size();l++) x += ss[l]-'0';
                // cout << "#: " << j << ' ' << sum-x*2 << ' ' << mp[{j,sum-x}] << ' ' << ss << endl;
                ans += mp[{j,sum-2*x}];
            }
        }
        sum = 0;
        for(int j=0;j<s.size();j++) sum += s[j]-'0';
        mp[{s.size(),sum}] ++;
    }
    ans = ans + n;
    cout << ans << endl;
}
signed main()
{
    IOS;
	int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}