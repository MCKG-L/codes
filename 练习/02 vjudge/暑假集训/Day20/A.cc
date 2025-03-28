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
const int N = 1e5 + 10;
int n;
void solve(){
    int a = 1e9 + 10,b = -1;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        a = min(a,x);b = max(b,x);
    }
    cout << b - a << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
