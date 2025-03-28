#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    // n = s.size();
    s = ' ' + s;
    vector<int> l(n+1),r(n+2);
    set<char> st;
    for(int i=1;i<=n;i++){
        l[i] = l[i-1];
        if(st.count(s[i])) continue;
        if(s[i] == 'k') st.insert(s[i]);
        if(s[i] == 'i' && st.find('k') != st.end()) st.insert(s[i]);
        if(s[i] == 'r' && st.find('i') != st.end()) st.insert(s[i]);
        if(s[i] == 'a' && st.find('r') != st.end()){
            l[i] ++;
            st.clear();
        }
    }
    st.clear();
    for(int i=n;i>=1;i--){
        r[i] = r[i+1];
        if(st.count(s[i])) continue;
        if(s[i] == 'i') st.insert(s[i]);
        if(s[i] == 'k' && st.find('i') != st.end()) st.insert(s[i]);
        if(s[i] == 'o' && st.find('k') != st.end()) st.insert(s[i]);
        if(s[i] == 'd' && st.find('o') != st.end()){
            r[i] ++;
            st.clear();
        }
    }
    int ans = 0;
    for(int i=1;i<n;i++){
        if(l[i] == 0 || r[i] == 0) continue;
        ans = max(ans,l[i]+r[i+1]);
    }
    cout << ans*4 << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}