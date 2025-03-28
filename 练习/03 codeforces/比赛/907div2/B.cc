#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> s;
    s.push_back(31);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<q;i++){
        int x;cin >> x;
        if(x < s.back()) s.push_back(x);
    }
    for(auto & x : a){
        for(auto k : s){
            if(x % (1<<k) == 0) x = x | (1 << k-1);
        }
    }
    for(auto i : a) cout << i << ' ';
    cout << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}