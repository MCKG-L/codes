#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353ll,inf = 1e9;
void solve(){
    int q;cin >> q;
    vector<int> a;
    a.reserve(q + 1);
    int L = 0,now = 0;
    while(q --){
        int op;
        cin >> op;
        if(op == 1){
            a.push_back(now);
        }else if(op == 2){
            int x;cin >> x;
            now += x;
        }else{
            int x;cin >> x;
            int l = L,r = a.size() - 1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(now - a[mid] >= x) l = mid + 1;
                else r = mid - 1;
            }
            cout << r - L + 1 << endl;
            L = r + 1;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}