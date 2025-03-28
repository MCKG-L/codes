#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10;
int a[N],tr[N],ans[N];
int n;
int lowbit(int x){
    return x & -x;
}
void add(int x,int c){
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
}
int get(int x){
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
    return res;
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        tr[i] = lowbit(i);//tr[i]表示以i结尾，长度为lowbit(i)的区间和
        if(i > 1) cin >> a[i];
    }
    for(int i=n;i>=1;i--){
        int k = a[i] + 1;
        int l = 1,r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(get(mid) >= k) r = mid;
            else l = mid + 1;
        }
        ans[i] = l;
        add(l,-1);
    }
    for(int i=1;i<=n;i++) cout << ans[i] << endl;
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}