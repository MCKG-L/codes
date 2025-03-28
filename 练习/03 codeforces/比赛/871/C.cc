#include <iostream>
#define end '\n'
using namespace std;
const int inf = 0x3f3f3f;
void solve(){
    int n;cin >> n;
    int a = inf,b = inf,c = inf;
    for(int i=0;i<n;i++){
        int x;string s;
        cin >> x >> s;
        if(s[0] == '1' && s[1] == '1'){
            c = min(c,x);
        }else if(s[0] == '1'){
            a = min(a,x);
        }else if(s[1] == '1'){
            b = min(b,x);
        }
    }
    int ans = 0;
    if(c == inf && (a == inf || b == inf)) ans = -1;
    else ans = min(a+b,c);
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}