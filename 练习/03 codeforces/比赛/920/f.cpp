#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using ll = long long;
void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n+10);
    for(int i=1;i<=n;i++) cin >> a[i];
    int pivot  = sqrt(n) + 1;
    vector<vector<int>> prec(pivot+10,vector<int>(n+10,0)),preci(pivot+10,vector<int>(n+10,0));
    //预处理
    for(int d=1;d<=pivot;d++){ //枚举步长
        for(int i=1;i<=d;i++){
            prec[d][i] = a[i];
            preci[d][i] = a[i];
        }
        for(int i=d+1;i<=n;i++){
            prec[d][i] = prec[d][i-d] + a[i];
            preci[d][i] = preci[d][i-d] + a[i] * ((i + d - 1) / d);
        }
    }
    while(q -- ){
        int s,d,k;
        cin >> s >> d >> k;
        int l = s,r = s + d * (k - 1);
        int ans = 0;
        if(d >= pivot){
            for(int i=1;i<=k;i++){
                ans += i * a[s + d*(i-1)];
            }
            cout << ans << ' ';
            continue;
        }
        ans = preci[d][r] - preci[d][max(0ll,l-d)] - ((l + d - 1) / d - 1)*(prec[d][r]-prec[d][max(0ll,l-d)]);
        cout << ans << ' ';
    }
    cout << endl;
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