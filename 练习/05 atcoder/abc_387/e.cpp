#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1010,inf = 3e18;
void solve(){
    string s;cin >> s;
    auto cal = [&](int s)->int{
        int x = 0;
        while(s){
            x += s % 10;
            s /= 10;
        }
        return x;
    };
    if(s.size() <= 6){
        int x = 0;
        for(int i=0;i<s.size();i++){
            x = x * 10 + s[i] - '0';
        }
        for(int i=x;i<x<<1;i++){
            if(i % cal(i) == 0 && ((i + 1) % cal(i + 1) == 0)){
                cout << i << endl;
                return;
            }
        }
        cout << -1 << endl;
        return;
    }
    int x = (s[0] - '0') * 10 + s[1] - '0';
    string k;
    if(x < 17) k = "17";
    else if(x < 26) k = "26";
    else if(x < 35) k = "35";
    else if(x < 44) k = "44";
    else if(x < 53) k = "53";
    else if(x < 62) k = "62";
    else k = "107";
    cout << k;
    for(int i=2;i<s.size();i++) cout << '0';
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}