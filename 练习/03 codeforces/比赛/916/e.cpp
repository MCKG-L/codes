#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using ll = long long;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int n;
// int a[N],b[N],c[N];
struct Node{
    int a,b,c;
    bool operator <(const Node p)const{
        return c > p.c;
    }
}p[N];
void solve(){
    cin >> n;    
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++){
        int x;cin >> x;
        p[i] = {a[i],x,a[i]+x};
    }
    sort(p,p+n);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(i & 0x1){
            ans += 1 - p[i].b;            
        }else{
            ans += p[i].a - 1;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}