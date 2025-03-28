#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int K[N];
void solve(){
    int n;cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        while(x % 2 == 0) cnt ++,x /= 2;
    }
    if(cnt >= n){
        cout << 0 << endl;
        return;
    }
    vector<int> p;
    for(int i=1;i<=n;i++){
        if(K[i]) p.push_back(K[i]);
    }
    sort(p.begin(),p.end(),[&](int a,int b){
        return a > b;
    });
    int d = n - cnt;
    for(int i=0;i<p.size();i++){
        d -= p[i];
        if(d <= 0){
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}
signed main()
{
    IOS;int T = 1;
    K[0] = K[1] = 0;
    for(int i=2;i<=N;i++){
        if(i % 2 == 0) K[i] = K[i>>1] + 1;
    }
    cin >> T;
    while(T--) solve();
    return 0;
}