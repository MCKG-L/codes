#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    vector<int> ans;
    if(n & 1){
        cout << -1 << endl;
        return;
    }
    for(int i=0;i<n/2;i++){
        if(s[i] == s[n-i-1]){
            if(s[i] == '0'){
                ans.push_back(n-i);
                s.insert(n-i,"01");n += 2;
            }else{
                ans.push_back(i);
                s.insert(i,"o1");n += 2;
            }
        }
        if(ans.size() > 300) break;
    }
    if(ans.size() > 300){
        cout << -1 << endl;
    }else{
        cout << ans.size() << endl;
        for(auto i : ans) cout << i << ' ';
        cout << endl;
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