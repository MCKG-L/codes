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
int n;
bool func(int x){
    if(x == 2) return 0;
    return __builtin_popcount(x) == 1 ? 1 : 0;
}
void solve(){
    cin >> n;
    if(func(n + 1)) cout << 1 << endl;
    else cout << 0 << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
