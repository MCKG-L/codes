#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using ll = long long;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int a[N],n;
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    map<int,int> mp;
    ll sum = 0;
    mp[0] = 1;
    for(int i=1;i<=n;i++){
        if(i & 1) a[i] *= -1;
        sum += a[i];
        if(mp[sum]){
            cout << "Yes" << endl;
            return;
        }
        mp[sum] ++;
    }
    cout << "No" << endl;
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