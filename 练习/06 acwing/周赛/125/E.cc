#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
bool f(string a,string b){
    a = a + a;
    for(int i=0;i<b.size();i++){
        if(b[i] >= 'a' && b[i] <= 'z') b[i] -= 32;
        else if(b[i] >= 'A' && b[i] <= 'Z') b[i] += 32;
    }
    // cout << a << ' ' << b << endl;
    int pos = a.find(b);
    if(pos != -1){
        cout << "Yes" << '\n' << pos << endl;
        return 1;
    }
    return 0;
}
void solve(){
    int n;cin >> n;
    string a,b;
    cin >> a >> b;
    if(!f(a,b)){
        if(!f(b,a)){
            cout << "No" << endl;
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