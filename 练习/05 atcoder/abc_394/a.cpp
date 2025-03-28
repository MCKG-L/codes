#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10;
void solve(){
    string s;cin >> s;
    stack<char> stk;
    map<char,char> mp;
    mp[']'] = '[',mp[')'] = '(',mp['>'] = '<'; 
    for(int i=0;i<s.size();i++){
        if(stk.size() == 0){
            if(s[i] == ')' || s[i] == ']' || s[i] == '>'){
                cout << "No" << endl;
                return;
            }
            stk.push(s[i]);
        }else{
            if(s[i] == '(' || s[i] == '<' || s[i] == '['){
                stk.push(s[i]);
            }else{
                if(stk.top() != mp[s[i]]){
                    cout << "No" << endl;
                    return;
                }else{
                    stk.pop();
                }
            }
        }
    }
    cout << (stk.size() ? "No" : "Yes") << endl;
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