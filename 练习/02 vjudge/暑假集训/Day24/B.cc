#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    string ans = "";
    for(int i=n-1;i>=0;i--){
        if(s[i] == '0'){
            int a = s[i-1]-'0' + 10 * (s[i-2]-'0');
            ans += 'a' + a - 1;
            i -= 2;
        }else{
            ans += 'a' + s[i] - '0' - 1;
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
