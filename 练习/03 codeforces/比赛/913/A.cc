#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
void solve(){
    string s;cin >> s;
    for(char i='a';i!='i';i++){
        if(i != s[0]){
            cout << i << s[1] << endl;
        }
    }
    for(int i=1;i<=8;i++){
        if(i != s[1]-'0'){
            cout << s[0] << i << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}