#include <iostream>
using namespace std;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    string ans = "";
    for(int i=0;i<n;i++){
        int j = i + 1;
        while(s[j] != s[i]) j ++;
        ans += s[i];
        i = j;
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}