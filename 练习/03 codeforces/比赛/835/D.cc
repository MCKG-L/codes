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
    for(int i=0;i<n;i++) cin >> a[i];
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(i == 0){
            int j = i + 1;
            while(j < n && a[j] == a[i]) j ++;
            if(j == n) cnt ++;
            else{
                if(a[j] > a[i]) cnt ++;
            }
            i = j - 1;
        }else{
            // while(i < n && a[i] < a[i-1]) i ++;
            // i --;
            while(i < n && a[i] >= a[i-1]) i ++;
            // i --;
            if(i == n) break;
            int j = i + 1;
            while(j < n && a[j] == a[i]) j ++;
            if(j == n) cnt ++;
            else if( a[j] > a[i]) cnt ++;
            i = j - 1;
        }
    }
    // cerr << "cnt:" << cnt << endl;
    if(cnt == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}