#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
void solve(){
    string s;cin >> s;
    auto f = [&](string s){
        if(s.size() == 0) return false;
        int l = 0,r = s.size() - 1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l ++,r --;
        }
        return true;
    };
    map<char,int> mp;
    bool ok = 0;
    for(int i=0;i<26&&i<s.size();i++){
        if(mp[s[i]] >= 1){
            ok = 0;
            break;
        }
        if(i + 1 < s.size() && s[i + 1] == s.back() && f(s.substr(i + 1))){
            ok = 1;break;
        }
        mp[s[i]] ++;
    }
    cout << (ok ? "HE" : "NaN") << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}