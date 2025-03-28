#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
int n,c,d;
int a[N];
void solve(){
    cin >> n >> c >> d;
    int sum = 0;
    for(int i=0;i<n;i++) cin >> a[i],sum += a[i];
    if(sum >= c){
        cout << "Infinity" << endl;
        return;
    }
    sort(a,a+n,[&](int a,int b){
        return a > b;
    });
    if(a[0] * d < c){
        cout << "Impossible" << endl;
        return;
    }
    
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}