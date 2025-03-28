#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<int> cnt(2,0);
    vector<bool> f(2,false);
    while(n--){
        int op,k;string x;
        cin >> op >> k >> x;
        op --;
        if(f[1]){
            cout << "YES" << endl;
            continue;
        }
        for(auto i : x){
            if(i == 'a') cnt[op] += k;
            else f[op] = 1;
        }
        if(f[1] || !f[0] && cnt[0] < cnt[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
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