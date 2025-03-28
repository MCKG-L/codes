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
int a[N];
int n;
void solve(){
    int n;cin >> n;
    int ans = 0;
    string s;cin >> s;
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '0' || s[i] == '?') cnt ++;
        else{
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    ans = max(ans,cnt);
    cnt = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '1' || s[i] == '?') cnt ++;
        else{
            ans = max(ans,cnt);
        }
    }
    ans = max(ans,cnt);
    cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
