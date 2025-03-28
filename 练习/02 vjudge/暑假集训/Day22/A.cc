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
const int N = 55;
int a[N];
int n;
void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int ans = 0;
    for(int i=0;i<n-1;i++){
        if(a[i] > a[i+1]){
            ans = max(ans,max(a[i],a[i+1]));
        }
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
