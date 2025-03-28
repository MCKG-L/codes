#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n;cin >> n;

    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        a[i] = x;
        mp[x] ++;
    }
    if(n < 4){
        cout << -1 << endl;
        return;
    }
    if(mp.size() < 2){
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    vector<int> k;
    for(auto [x,y] : mp){
        if(y >= 2){
            k.push_back(x);
            cnt ++;
        }
    }
    if(cnt < 2){
        cout << -1 << endl;
        return;
    }
    cnt = 0;
    int mask = k[0];
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        if(a[i] == mask){
            if(cnt == 0){
                ans[i] = 1;
                cnt ++;
            }else{
                if(cnt == 1){
                    ans[i] = 2;
                }
            }
        }
    }
    mask = k[1];
    cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i] == mask){
            if(cnt == 0){
                ans[i] = 1;
                cnt ++;
            }else if(cnt == 1){
                ans[i] = 3;
            }
        }
    }
    for(auto i : ans){
        if(i != -1) cout << i << ' ';
        else cout << 1 << ' ';
    }
    cout << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}