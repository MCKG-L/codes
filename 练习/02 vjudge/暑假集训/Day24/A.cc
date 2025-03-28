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
    int a,b,c;
    cin >> a >> b >> c;
    int ans = a - 1;
    int d = abs(b-c) + c - 1;
    if(ans < d) cout << 1 << endl;
    else if(ans > d) cout << 2 << endl;
    else cout << 3 << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
