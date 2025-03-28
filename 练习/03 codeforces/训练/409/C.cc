#include <iostream>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
const int N = 2e5+10;
int cnt[N];
set<int> s;
void solve(){
    memset(cnt,0,sizeof cnt);
    s.clear();
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        cnt[x] ++;
        s.insert(x);
    }
    int max_n = 1,min_n = n + 1;
    for(int i=0;i<=n;i++){
        max_n = max(max_n,cnt[i]);
    }
    int a = max_n,b = s.size()-1;
    int ans = min(a,b);
    int ans2 = min(a-1,b+1);
    cout << max(ans,ans2) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}