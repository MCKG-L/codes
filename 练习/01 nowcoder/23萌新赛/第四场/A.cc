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
int n,s;
void solve(){
    cin >> n >> s;
    int k = s / n;
    int r = s % n;
    vector<int> ans(n,k);
    for(int i=n-1;i>=0&&r;i--){
        ans[i] ++;r--;
    }
    for(auto i : ans) cout << i << ' ';
    cout << endl;
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
