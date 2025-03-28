#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int p[N],q[N];
int a[N],b[N];
int W,H,n,A,B;
map<pair<int,int>,int> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> W >> H >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i] >> q[i];
    }
    cin >> A;a[A+1] = W;
    for(int i=1;i<=A;i++) cin >> a[i];
    cin >> B;b[B+1] = H;
    for(int i=1;i<=B;i++) cin >> b[i];
    for(int i=1;i<=n;i++){
        int x = lower_bound(a+1,a+A+2,p[i])-a;
        int y = lower_bound(b+1,b+B+1,q[i])-b;
        mp[{x,y}] ++;
    }
    int M = 0,m = 1e6;
    for(auto i : mp){
        M = max(M,i.second);
        m = min(m,i.second);
    }
    if(mp.size() != (A+1)*(B+1)) m = 0;
    cout << m << ' ' << M << endl;
    return 0;
}