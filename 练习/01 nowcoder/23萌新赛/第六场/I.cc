#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
void solve(){
    int n;cin >> n;
    vector<string> p;
    string s;
    for(int i=31;i>=0;i--){
        s += ((n >> i & 1)+'0');
        if(s.size() == 8) p.push_back(s),s.clear();
    }
    sort(p.begin(),p.end(),[&](string p1,string p2){
        return p1 + p2 > p2 + p1;
    });
    for(int i=0;i<4;i++) cout << s;
    cout << endl;
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
