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
const int N = 2e6 + 10;
int a[N];
int n;
map<int,int> mp;
void solve(){
    cin >> n;
    mp.clear();
    int k = n - 1;
    n = n * (n - 1) / 2;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        mp[x] ++;
    }
    for(auto [x,t] : mp){
        while(k && t > 0 && t >= k){
            cout << x << ' ';
            t -= k;
            k --;
        }
    }
    cout << (int)(1e9) << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
