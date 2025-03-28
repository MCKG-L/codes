#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    vector<array<int,3>> p;
    int n,m,h;
    cin >> n >> m >> h;

    vector<int> a(m);
    for(int i=0;i<n;i++){
        int t = h,cnt = 0,sum = 0,now = 0;
        for(int j=0;j<m;j++) cin >> a[j];
        sort(a.begin(),a.end());
        // for(auto i : a) cout << i << ' ';
        // cout << endl;
        for(int j=0;j<m;j++){
            int x = a[j];
            if(t >= x){
                now += x;
                t -= x;cnt ++;
                sum += now;
            }
        }
        p.push_back({cnt,-sum,-i});
    }
    // for(auto [x,y,t] : p){
    //     cout << -t << ": " << x << ": " << -y << endl;
    // }
    sort(p.begin(),p.end());
    int k = 0;
    for(auto [x,y,id] : p){
        k ++;
        if(id == 0){
            cout << n - k + 1 << endl;
            return;
        }
    }
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}