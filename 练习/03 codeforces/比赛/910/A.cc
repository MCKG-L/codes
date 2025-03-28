#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n,k;
    cin >> n >> k;
    string s;cin >> s;
    s = ' ' + s;
    vector<int> cnt(n+10);
    cnt[n+1] = 0;
    for(int i=n;i>=1;i--){
        cnt[i] = cnt[i+1];
        if(s[i] == 'B') cnt[i] ++;
    }
    if(cnt[1] == k){
        cout << 0 << endl;
        return;
    }
    if(cnt[1] > k){
        int d = cnt[1] - k;
        for(int i=1;i<=n;i++){
            if(s[i] == 'B') d --;
            if(d == 0){
                cout << 1 << endl;
                cout << i << ' ' << "A" << endl;
                return;
            }
        }
    }
    int d = k - cnt[1];
    for(int i=1;i<=n;i++){
        if(i + cnt[i+1] == k){
            cout << 1 << endl;
            cout << i << ' ' << 'B' << endl;
            return;
        }
    }
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}