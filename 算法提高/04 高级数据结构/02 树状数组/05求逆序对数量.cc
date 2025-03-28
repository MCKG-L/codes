#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
vector<int> alls,a;
int n;
int tr[N];
int find(int x){
    return lower_bound(alls.begin(),alls.end(),x)-alls.begin() + 1;
}
int lowbit(int x){return x & -x;}
void add(int x,int t){
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += t;
}
int sum(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i)) ans += tr[i];
    return ans;
}
void solve(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        a.push_back(x);
        alls.push_back(x);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    int ans = 0;
    // for(int i=n-1;i>=0;i--){
    //     int x = find(a[i]);
    //     ans += sum(x-1);
    //     add(x,1);
    // }
    for(int i=0;i<n;i++){
        int x = find(a[i]);
        ans += i - sum(x);
        add(x,1);
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