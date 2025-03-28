#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve(){
    string s;cin >> s;
    if((s.back() - '0') % 2 == 0){
        cout << s << endl;
        return;
    }
    for(int i=0;i<5;i++){
        if((s[i] - '0') % 2 == 0){
            swap(s[i],s.back());
            cout << s << endl;
            return;
        }
    }
    cout << "97531" << endl;
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