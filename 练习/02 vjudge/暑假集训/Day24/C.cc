#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define lx first
#define ly second
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
vector<PII> p;
bool cmp(PII p1,PII p2){
    if(p1.lx != p2.lx) return p1.lx > p2.lx;
    return p1.ly < p2.ly;
}
void solve(){
    p.clear();
    string s;cin >> s;
    int n = s.size();
    int a = min(s[0],s[n-1]);
    int b = max(s[0],s[n-1]);
    for(int i=0;i<n;i++){
        if(s[i] >= a && s[i] <= b){
            p.push_back({s[i]-'a'+1,i+1});
        }
    }
    sort(p.begin(),p.end());
    int ans = 0;
    n = p.size();
    for(int i=1;i<n;i++){
        ans += p[i].lx - p[i-1].lx;
    }
    cout << ans << ' ' << p.size() << endl;
    if(s[0] > s.back()) sort(p.begin(),p.end(),cmp);
    for(int i=0;i<n;i++){
        cout << p[i].ly << ' ';
    }
    cout << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
