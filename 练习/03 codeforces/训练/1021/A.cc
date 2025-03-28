#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
// char s[N];
void solve(){
    // cin >> n;
    string s;cin >> s;
    // cout << "s:" << s << endl;
    vector<int> ans;
    int n = s.size();
    // cout << s << endl;
    // cout << s.substr(0,3) << endl;
    for(int i=0;i<n;i++){
        // cerr << "i:" << i << endl;cerr不经过缓冲区，直接输出
        if(s[i] == 'o'){
            // cout << "i:" << i << endl;
            while(i < n &&  s[i] == 'o') i ++;
            i --;
            // cout << i << "iiii" << endl;
            if(s.substr(i,3) == "one"){
                // cout << "YES" << endl;
                ans.push_back(i+1);
                s[i+1] = '*';
                i += 2;
            }
        }else if(s[i] == 't'){
            while(i < n && s[i] == 't') i ++;
            i --;
            if(s.substr(i,5) == "twone"){

                ans.push_back(i + 2);
                s[i+2] = '*';
                // cout << "s:" << s << endl;
                i += 4;
            }else if(s.substr(i,3) == "two"){
                ans.push_back(i+1);
                s[i+1] = '*';
                i += 2;
            }
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i + 1 << ' ';
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}