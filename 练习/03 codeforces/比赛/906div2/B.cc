#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n,m;cin >> n >> m;
    string s,t;
    cin >> s >> t;
    int cnt0 = 0,cnt1 = 0;
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            if(s[i] == '0') cnt0 ++;
            else cnt1 ++;
        }
    }
    bool f = 1;
    for(int i=0;i<m-1;i++){
        if(t[i] == t[i+1]){
            f = 0;break;
        }
    }
    if(cnt0 == 0 && cnt1 == 0){
        cout << "Yes" << endl;
        return;
    }
    if(f == 0 || (m % 2 == 0)){
        cout << "No" << endl;
        return;
    }
    if(cnt0 == 0 && cnt1 != 0){
        if(t[0] == '0') cout << "Yes" << endl;
        else cout << "No" << endl;
    }else if(cnt0 != 0 && cnt1 == 0){
        if(t[0] == '1') cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        cout << "No" << endl;
    }
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}