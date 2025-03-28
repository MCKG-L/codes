#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
typedef pair<int,int> PII;
unordered_map<char,int> mp = {{'+',1},{'-',1},{'*',2},{'/',2}};
stack<char> op;
void solve(){
    string str;cin >> str;
    int n = str.size();
    string emptyStr = "";
    vector<string> s;//保存后缀表达式
    for(int i=0;i<n;i++){
        char c = str[i];
        if(isdigit(c)){
            int j = i;string k = "";
            while(j < n && isdigit(str[j])) k = k + str[j++];
            s.push_back(k);
            i = j - 1;
        }else if(c == '(') op.push(c);
        else if(c == ')'){
            while(op.size() && op.top() != '(') s.push_back(op.top() + emptyStr),op.pop();
            op.pop();
        }else{
            while(op.size() && mp[c] <= mp[op.top()]){
                s.push_back(op.top() + emptyStr);op.pop();
            } 
            op.push(c);
        }
    }
    while(op.size()) s.push_back(op.top() + emptyStr),op.pop();
    for(auto i : s) cout << i << ' ';
    cout << endl;
}
void solve1(){
    string s;
    cin >> s;
    int n = s.size();
    string S = "";
    stack<string> ans;
    stack<char> op;
    for(int i=0;i<n;i++){
        char c = s[i];
        if(c == '(') op.push(c);
        else if(c == ')'){
            while(op.size() && op.top() != '(') ans.push(op.top()+S),op.pop();
            op.pop();
        }else if(isdigit(c)){
            int j = i;
            string k = "";
            while(j < n && isdigit(s[j])) k = k + s[j++];
            ans.push(k);
            i = j - 1;
        }else{
            while(op.size() && mp[c] <= mp[op.top()]) ans.push(op.top()+S),op.pop();
        }
    }
    auto dfs = [&](auto &&dfs)->void{
        if(ans.size()){
            dfs(dfs);
            cout << ans.top() << ' ';
            ans.pop();
        }
    };
    dfs(dfs);
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}