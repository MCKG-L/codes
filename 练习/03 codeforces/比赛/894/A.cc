#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N =22;
char s[N][N];
void solve(){
    int n,m;
    cin >> n >> m;
    map<char,int> book[m];
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            book[j].insert({s[i][j],1});
        }
    }
    bool ok = 0;
    string ss = "vika";
    int k = 0;
    for(int i=0;i<m;i++){
        if(book[i].count(ss[k])){
            k ++;
            if(k >= 4) ok = 1;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}