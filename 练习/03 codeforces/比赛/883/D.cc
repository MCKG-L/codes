#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
double s(double a,double b,double c = 0){
    return (a + c) * b / 2;
}
void solve(){
    int n,a,h;
    cin >> n >> a >> h;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    double ans = 0;
    for(int i=1;i<n;i++){
        double dif = p[i] - p[i-1];
        if(dif >= h) ans += s(a,h);
        else ans += s(a,dif,a-a*dif/h);
    }
    ans += s(a,h);
    printf("%.6f\n",ans);
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}