#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> cnt(k);
    for(int i=0;i<k;i++){
        cnt[i] = (n - 1 - i) / k + 1;
    }
    for(int i=0;i<k;i++){
        cout << cnt[i] << ' ';
    }
    int cnt0 = n / 2;
    int cnt1 = n - cnt0;
    
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}