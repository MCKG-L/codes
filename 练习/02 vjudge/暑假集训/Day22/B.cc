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
    int cnt = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x == 1) cnt --;
        else cnt += x-1;
    }
    if(cnt >= 0 && n > 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
