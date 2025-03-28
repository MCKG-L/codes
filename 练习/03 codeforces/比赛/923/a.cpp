#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
void solve(){
    int n,m,k;cin >> n >> m >> k;
    map<int,int> mp1,mp2;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        mp1[x] ++;
    }
    for(int i=0;i<m;i++){
        int x;cin >> x;
        mp2[x] ++;
    }
    int cnt1 = 0,cnt2 = 0;
    for(int i=1;i<=k;i++){
        if(mp1.count(i) && mp2.count(i)){
            continue;
        }else if(mp1.count(i)){
            cnt1 ++;
            if(cnt1 > k / 2){
                cout << "NO" << endl;
                return;
            }
        }else if(mp2.count(i)){
            cnt2 ++;
            if(cnt2 > k / 2){
                cout << "NO" << endl;
                return;
            }
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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