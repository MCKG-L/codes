#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1e5 + 10;
/*
给定一个包含 n 个字符串的字符串数组 s1,s2,…,sn 和一个短字符串 p
，找出字符串数组中所有能够和短字符串匹配的字符串。
匹配时不区分大小写，短字符串中可能包含若干个用中括号表示的模式匹配。
例如，对于 aa[123]bb，字符串 aa1bb、aa2bb、aa3bb 均可与其匹配（每次匹配只能与中括号中的任意单个字符进行匹配）。
4
Aab
a2B
ab
ABB
a[a2b]b

输出：
1 Aab
2 a2B
4 ABB
*/
void solve(){
    int n;cin >> n;
    vector<string> a(n + 1),b(n + 1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[i] = a[i];
        for(auto &c : a[i]){
            if(islower(c)) c -= 32;
        }
    }
    string s;cin >> s;
    for(auto &c : s){
        if(islower(c)){
            c -= 32;
        }
    }
    int m = s.size();
    s = ' ' + s;
    int ver = 0;
    vector<int> st(n + 1,true);
    
    for(int i=1;i<=m;i++){
        ver ++;
        if(s[i] == '['){
            int j = i;
            set<char> S;
            while(j <= m && s[j] != ']'){
                S.insert(s[j]);
                j ++;
            }
            i = j;
            for(int j=1;j<=n;j++){
                if(ver <= a[j].size() && S.count(a[j][ver-1])){
                    continue;
                }else{
                    st[j] = 0;
                }
            }
        }else{
            for(int j=1;j<=n;j++){
                if(ver <= a[j].size() && a[j][ver-1] == s[i]){
                    continue;
                }else{
                    st[j] = 0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(st[i]){
            cout << i << ' ' << b[i] << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}
