#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int n,k;
    cin >> n >> k;
    map<char,int> mp;
    string s;cin >> s;
    for(auto i : s) mp[i] ++;
    int d = n - k;
    int cnt = 0;
    bool f = 0;
    for(auto &[x,y] : mp){
        if(y & 1) cnt += y-1,y = 1;
        else cnt += y,y = 0;
    }
    if(cnt >= d){
        cout << "YES" << endl;
    }else{
        if(d & 1){
            if(cnt + 1 >= d){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            cout << "NO" << endl;
        }
    }
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}