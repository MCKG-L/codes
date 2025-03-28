#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;

void solve(){
    multiset<int> s;
    int n;cin >> n;
    // vector<int> a(n+10);
    vector<bool> st(n+10,false);
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        // a[i] = x;
        s.insert(x);
    }
    for(auto i : s){
        cout << i << ' ';

    }
    cout << endl;
    // a[0] = -1e9,a[n+1] = -1e9;
    int cnt = 0;
    while(1){
        cnt ++;
        vector<int> a,del;
        for(auto i : s){
            a.push_back(i);
            cout << i << ' ';
        }
        cout << endl;
        for(int i=0;i<a.size();i++){
            if(i == 0 && a[i] < a[i+1]) del.push_back(a[i]);
            else if(i == a.size()-1 && a[i] < a[i-1]) del.push_back(a[i]);
            else{
                if(a[i] < a[i+1] || a[i] < a[i-1]) del.push_back(a[i]);
            }
        }
        
        for(auto i : del){
            cout << "del:" << i << ' ';
            s.erase(s.find(i));
        }
        if(s.size() <= 2) break;
    }
    // for(auto i : s) cout << "i:" << i << ' ';
    cout << endl;
    cout << s.size() << endl;
    if(s.size() > 1) cnt ++;
    cout << cnt << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}