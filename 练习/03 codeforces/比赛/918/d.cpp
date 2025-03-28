#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using ll = long long;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    string S = s;
    for(int i=0;i<n;i++){
        if(s[i] == 'b' || s[i] == 'c' || s[i] == 'd') s[i] = '0';
        else s[i] = '1';
    }
    vector<int> pos,ans(n+1,0);
    for(int i=0;i<n-1;i++){
        if(s[i] == '0' && s[i+1] == '0'){
            pos.push_back(i + 1);
        }
    }
    int l = 1;
    pos.push_back(n);
    for(auto p : pos){
        int r = p;
        ans[r] = 1;
        if((r - l + 1) & 1){
            r -= 3;
        }else r -= 2;
        for(int i=l;i<=r;i+=2){
            ans[i+1] = 1;
        }
        l = p + 1;
    }
    ans[n] = 0;
    // cout << s << endl;
    for(int i=1;i<=n;i++){
        cout << S[i-1];
        if(ans[i]) cout << '.';
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}