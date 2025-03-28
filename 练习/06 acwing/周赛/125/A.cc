#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 3e5 + 10;
int a[N],n,b[N];
void solve(){
    cin >> n;
    map<int,int> mp;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        b[i] = a[i];
        mp[a[i]] ++;
    }
    sort(b+1,b+1+n);
    int ans = 0;
    set<int> s;
    for(int i=1;i<=3;i++){
        s.insert(b[i]);
    }
    if(s.size() == 1){
        int y = mp[b[1]];
        ans = y * (y-1) * (y-2) / 6;
    }else if(s.size() == 2){
        int y1 = mp[b[1]];
        int y2 = mp[b[3]];
        ans = y1*(y1-1)/2 * y2;
    }else if(s.size() == 3){
        ans = mp[b[1]] * mp[b[2]] * mp[b[3]];
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}