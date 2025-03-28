#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    string s;cin >> s;
    int n = s.size();
    vector<PII> a;
    int k;cin >> k;
    int id = 1;
    for(int i=0;i<n;i++){
        char c = s[i];
        if(isdigit(c)){
            int k = 0,j = i;
            while(isdigit(s[j])) k = k * 10 + s[j++]-'0';
            a.push_back({k,id++});
            i = j - 1;
        }else if(c == '-'){
            int k = 0,j = i + 1;
            while(isdigit(s[j])) k = k * 10 + s[j++]-'0';
            a.push_back({-k,id++});
            i = j - 1;
        }
    }
    for(auto [x,y] : a){
        cout << x << ' ' << y << endl;
    }
    cout << endl;
    sort(a.begin(),a.end(),[&](PII p1,PII p2){
        if(p1.first != p2.first) return p1.first > p2.first;
        return p1.second < p2.second;
    });
    vector<int> ans;
    for(int i=0;i<k;i++) ans.push_back(a[i].second);
    sort(ans.begin(),ans.end());
    for(auto i : ans) cout << i << ' ';
    cout << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}