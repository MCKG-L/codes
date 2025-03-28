#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef unsigned long long ull;
//字符串哈希
const int N = 2e5 + 10,P = 131;
ull p[N];
char s[N];
map<ull,int> mp;
ull hash1(){
    int n = strlen(s+1);
    for(int i=1;i<=n;i++){
        p[i] = p[i-1]*P+s[i];
    }
    return p[n];
}
ull hash2(){
    int n = strlen(s+1);
    for(int i=1;i<=n;i++){
        p[i] = p[i-1]*P+s[n-i+1];
    }
    return p[n];
}
void solve(){
    int m;cin >> m;
    while(m--){
        cin >> s + 1;
        ull h1 = hash1(),h2 = hash2();
        if(!mp.count(h1) && !mp.count(h2)) mp[h1] ++;
    }
    cout << mp.size() << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}