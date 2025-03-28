#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;
    cin >> n >> q;
    while(q--){
        string s;cin >> s;
        int ans = 1;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'L') ans = ans * 2 - 1;
            if(s[i] == 'R') ans = ans * 2;
        }
        cout << ans << endl;
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}