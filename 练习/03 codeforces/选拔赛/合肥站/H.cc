#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int cal(char c){
    if(isdigit(c)){
        return c - '0' + 26;
    }
    return c - 'a';
}
void solve(){
    string s,t;
    cin >> s >> t;
    int n = s.size(),m = t.size();
    vector<vector<int>> ne(n+1,vector<int>(40,-1));
    for(int i=n-2;i>=0;i--){
        ne[i] = ne[i+1];
        ne[i][cal(s[i+1])] = i + 1;
    }
    int mn = 1e9;
    int l = 0,r = n;
    int now = 0;
    for(int i=0;i<n;i++){
        if(s[i] != t[0]) continue;
        now = i;
        bool f = 1;
        for(int j=1;j<m;j++){
            now = ne[now][cal(t[j])];
            if(now == -1){
                f = 0;break;
            }
        }
        if(!f) break;
        if(now - i + 1 < mn){
            mn = now - i + 1;
            l = i,r = now;
        }
    }
    for(int i=l;i<=r;i++) cout << s[i];
    cout << endl;
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}