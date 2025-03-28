#include <iostream>
using namespace std;
int a,b;
string ans;
void dfs(int x){
    if(x == a){
        ans = "YES";
        return;
    }
    if(x > a) return;
    dfs(x * 3);
    if(x % 2 == 0) dfs(x / 2 * 3);
}
void solve(){
    ans = "NO";
    cin >> a >> b;
    if(a < b){
        cout << "NO" << endl;
        return;
    }
    dfs(b);
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}