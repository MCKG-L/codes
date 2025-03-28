#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
char s[3][3];
bool check(char c){
    for(int i=0;i<3;i++){
        if(s[i][0] == c && s[i][1] == c && s[i][2] == c){
            return 1;
        }
        if(s[0][i] == c && s[1][i] == c && s[2][i] == c){
            return 1;
        }
    }
    if(s[0][0] == c && s[1][1] == c && s[2][2] == c) return 1;
    if(s[0][2] == c && s[1][1] == c && s[2][0] == c) return 1;
    return 0;
}
void solve(){
    for(int i=0;i<3;i++) cin >> s[i];
    if(check('X')) cout << "X" << endl;
    else if(check('O')) cout << "O" << endl;
    else if(check('+')) cout << "+" << endl;
    else cout << "DRAW" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}