#include <iostream>
#include <vector>
#include <map>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int p[N],q[N];
int a[N],b[N];
int W,H;
map<pair<int,int>,int> mp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> W >> H;
    int n;cin >> n;
    for(int i=1;i<=n;i++) cin >> p[i] >> q[i];
    int A,B;
    cin >> A;
    for(int i=1;i<=A;i++) cin >> a[i];
    cin >> B;
    for(int i=1;i<=B;i++) cin >> b[i];
    a[A+1] = W,b[B+1] = H;
    for(int i=1;i<=n;i++){
        int x = lower_bound(a+1,a+A+2,p[i])-a;
        int y = lower_bound(b+1,b+B+2,q[i])-b;
        mp[{x,y}]++;
    }
    int m = 1e6,M = 0;
    for(auto i : mp){
        M = max(M,i.second);
        m = min(m,i.second);
    }
    if(mp.size() != (A+1)*(B+1)) m = 0;
    cout << m << ' ' << M << endl;
    return 0;
}