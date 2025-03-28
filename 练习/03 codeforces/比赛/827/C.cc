#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    char s[10][10];
    int n = 8;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++){
        bool f = 1;
        for(int j=0;j<n;j++){
            if(s[i][j] != 'R'){
                f = 0;break;
            }
        }
        if(f){
            cout << "R" << endl;
            return;
        }
    }
    for(int i=0;i<n;i++){
        bool f = 1;
        for(int j=0;j<n;j++){
            if(s[j][i] != 'B'){
                f = 0;break;
            }
        }
        if(f){
            cout << "B" << endl;
            return;
        }
    }
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}