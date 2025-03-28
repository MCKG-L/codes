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
    vector<string> a(n);
    for(int i=0;i<n;i++){
        string s;cin >> s;
        a[i] = s;
    }
    sort(a.begin(),a.end(),[&](string s1,string s2){
        return s1.size() < s2.size();
    });
    int ans = 0;
    auto find = [&](string s,int sum) -> int {
        int len = s.size();
        int res = 0;
        for(int i=1;i<=5;i++){
            if(((i + len) & 1) || i > len) continue;
            int d = (len - i) / 2;
            string ss = s.substr(0,d);
            int x = 0;
            for(int j=0;j<ss.size();j++) x += ss[j]-'0';
            res += mp[{i,sum-x*2}];
        }
        return res;
    };
    for(int i=0;i<n;i++){
        string s = a[i];
        int sum = 0,len = s.size();
        for(int j=0;j<len;j++) sum += s[j]-'0';
        ans += find(s,sum);
        reverse(s.begin(),s.end());
        ans += find(s,sum);
        s = a[i];
        mp[{len,sum}] ++;
    }
    cout << ans + n << endl;
}
signed main()
{
    IOS;
	int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}