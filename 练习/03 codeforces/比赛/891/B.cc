#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    string s;cin >> s;
    int n = s.size();
    if(s[0] >= '5' && s[0] <= '9'){
        cout << 1;
        for(int i=0;i<n;i++) cout << 0;
        cout << endl;
        return;
    }
    s = '0' + s;
    n ++;
    int pos = 0;
    for(int i=0;i<n;i++){
        if(s[i] >= '5'){
            pos = i;break;
        }
    }
    if(pos == 0){
        for(int i=1;i<n;i++) cout << s[i];
        cout << endl;
        return;
    }
    pos --;
    while(pos &&  s[pos] == '4') pos --;
    s[pos] ++;
    if(s[0] > '0') cout << s[0];
    for(int i=1;i<=pos;i++){
        cout << s[i];
    }
    for(int i=pos+1;i<n;i++) cout << 0;
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}