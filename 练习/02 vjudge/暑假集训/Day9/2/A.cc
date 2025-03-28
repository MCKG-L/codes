#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
int a[8],b[8];
void solve(){
    for(int i=0;i<8;i++) cin >> a[i],b[i] = a[i];
    sort(b,b+8);
    for(int i=0;i<8;i++){
        bool f = 0;
        if(a[i] != b[i]) f = 1;
        if(a[i] % 25) f = 1;
        if(a[i] < 100 || a[i] > 675) f = 1;
        if(f){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}