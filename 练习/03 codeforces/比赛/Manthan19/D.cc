#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int t[N],s[N],n;
int ans[N];
/*
迷一样的牛 变形题
*/
int lowbit(int x){
    return x & -x;
}
void add(int x,int c){
    for(int i=x;i<=n;i+=lowbit(i)) t[i] += c;
}
int sum(int x){
    int res = 0;
    for(int i=x;i>0;i-=lowbit(i)) res += t[i];
    return res;
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i];
        add(i,i);
    }
    for(int i=n;i>=1;i--){
        int h = s[i] + 1;
        int l = 1,r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(sum(mid) >= h) r = mid;
            else l = mid + 1;
        }
        ans[i] = l;
        add(l,-l);
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}   
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}