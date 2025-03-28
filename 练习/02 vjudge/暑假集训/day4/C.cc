#include <iostream>
using namespace std;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    int ans = n;
    int l = 0,r = n-1;
    while(l < r){
        if(s[l] != s[r]) ans -= 2;
        else{
            break;
        }
        l ++,r --;
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}