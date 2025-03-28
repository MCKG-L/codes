#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;
const double esp = 1e-18;
void solve(){
    int q;cin >> q;
    while(q--){
        int k;cin >> k;
        int l = 1,r = 2e9;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(mid * (mid * 2 - 1) <= k) l = mid;
            else r = mid - 1;
        }
        int M = l;
        int d = k - l * (l * 2 - 1);
        if(d == 0){
            cout << 0 << endl;
            continue;
        }
        if(2*M+1 >= d){
            if(d == 1 || d == 2 * M + 1){
                cout << 0 << endl;
            }else if(M + 1 >= d){
                cout << d - 1 << endl;
            }else{
                d = 2 * M + 1 - d;
                cout << d << endl;
            }
        }else{
            if(d <= 3 * M + 1){
                cout << -(d-2*M-1) << endl;
            }else{
                cout << -(4*M+1-d) << endl;
            }
        }
    }
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}