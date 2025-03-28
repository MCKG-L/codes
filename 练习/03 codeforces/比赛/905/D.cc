#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
multiset<PII> s1,s2;
void f(){
    if(s1.size() <= 1){
        cout << "NO" << endl;
        return;
    }
    auto [x1,y1] = *prev(s1.end());
    auto [y2,x2] = *s2.begin();
    if(x1 > y2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
void solve(){
    
    int n;cin >> n;
    while(n--){
        string op;int l,r;
        cin >> op >> l >> r;
        if(op == "+"){
            s1.insert({l,r});
            s2.insert({r,l});
            f();
        }else{
            s1.erase(s1.find({l,r}));
            s2.erase(s2.find({r,l}));
            f();
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