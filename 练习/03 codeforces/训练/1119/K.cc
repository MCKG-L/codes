#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    multiset<int> s1,s2;
    int n;cin >> n;
    while(n--){
        string op;
        int l,r;
        cin >> op >> l >> r;
        if(op == "+"){
            s1.insert(l);
            s2.insert(r);
        }else{

            s1.erase(s1.find(l));
            s2.erase(s2.find(r));
        }
        if(!s1.size()){
            cout << "NO" << endl;
            continue;
        }
        int L = 0;
        if(s1.size() > 1) L = *prev(s1.end());
        else L = *s1.begin();
        int R = *s2.begin();
        if(L > R){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}