#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
vector<int> a,b;
int n;
void solve(){
    a.clear();b.clear();
    cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x < 0) a.push_back(x);
        else b.push_back(x);
    }
    if(a.size()) sort(a.begin(),a.end());
    if(b.size()) sort(b.begin(),b.end());
    int ans = 0;
    // if(b.size()) ans = b.back();
    if(a.size() == 1 && b.size() == 1) ans = a[0] * b[0];
    if(a.size() >= 2) ans = max(ans,a[0]*a[1]);
    if(b.size() >= 2) ans = max(ans,b.back()*b[b.size()-2]);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}