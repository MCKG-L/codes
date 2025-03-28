#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
multiset<int> s,ans;
void solve(){
    int m;cin >> m;
    while(m--){
        int op;cin >> op;
        if(op == 1){
            int x;cin >> x;
            auto p = s.lower_bound(x);
            if(p != s.begin()) ans.insert(x^*prev(p));
            if(p != s.end()) ans.insert(x^*p);
            if(p != s.begin() && p != s.end()) ans.erase(ans.find(*prev(p)^*p));
            s.insert(x);
        }else if(op == 2){
            int x;cin >> x;
            s.erase(s.find(x));
            auto p = s.lower_bound(x);
            if(p != s.begin()) ans.erase(ans.find(*prev(p)^x));
            if(p != s.end()) ans.erase(ans.find(*p^x));
            if(p != s.begin() && p != s.end()) ans.insert(*p^*prev(p));
        }else{
            cout << *ans.begin() << endl;
        }
    }
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}