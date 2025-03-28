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
int a[N],b[N];
int n;
map<PII,int> mp;
PII calc(int a,int b){
    int gcd = __gcd(a,b);
    a /= gcd,b /= gcd;
    return {a,b};
}
void solve(){
    cin >> n;
    mp.clear();
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    int ans = 0;
    for(int i=0;i<n;i++){
        PII p = calc(a[i],b[i]);
        ans += mp[p];
        mp[calc(b[i],a[i])] ++;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
