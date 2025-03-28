#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
void solve(){
    string s;cin >> s;
    set<int> p1,p2;
    for(int i=0;i<s.size();i++){
        char c = s[i];
        if(c == 'b'){
            s[i] = '#';
            if(p1.size()){
                int p = *prev(p1.end());
                s[p] = '#';
                p1.erase(p1.find(p));
            }
        }else if(c == 'B'){
            s[i] = '#';
            if(p2.size()){
                int p = *prev(p2.end());
                s[p] = '#';
                p2.erase(p2.find(p));
            }
        }else{
            if(c >= 'a' && c <= 'z') p1.emplace(i);
            else if(c >= 'A' && c <= 'Z') p2.emplace(i);
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i] != '#') cout << s[i];
    }
    cout << endl;
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