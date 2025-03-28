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
int a[N],tr[N];
int n,m;
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
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        add(i,a[i]-a[i-1]);
    }
    while(m--){
        string op;cin >> op;
        if(op == "C"){
            int l,r,c;
            cin >> l >> r >> c;
            add(l,c),add(r+1,-c);
        }else{
            int x;cin >> x;
            cout << get(x) << endl;
        }
    }

}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}