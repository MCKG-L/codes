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
const int N = 1010;
int a[N];
int n,k;
bool check(int x){
    for(int i=1;i<=n;i++){
        int s = 0;
        for(int j=i;j<=n;j++){
            if(a[j] < x-j+i) s += x-j+i-a[j];
            else if(s <= k) return 1;
        }
    }
    return 0;
}
void solve(){
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    int l = 0,r = 2e8;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
