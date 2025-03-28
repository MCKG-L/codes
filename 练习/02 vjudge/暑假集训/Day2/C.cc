#include <iostream>
#include <map>
using namespace std;
char s[2010];
void solve(){
    map<char,int> pos;
    int n;cin >> n;
    char c;
    string ans = "YES";
    for(int i=0;i<n;i++){
        cin >> c;
        if(pos.count(c) && (i - pos[c]) & 1){
            ans = "NO";
        }
        pos[c] = i;
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}