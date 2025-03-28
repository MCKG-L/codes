#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int a[N];
int n;
map<string,bool> mp;
void solve(){
    mp.clear();
    cin >> n;
    string s;
    bool flag = 0;
    while(n--){
        cin >> s;
        if(s == "sudo"){
            string a,b,c;
            cin >> a >> b;
            if(a == "rm"){
                if(flag == 0) cout << "wuwuwu" << endl;
                flag = 1;
                continue;
            }
            cin >> c;
            mp[c] = 1;
        }else if(s == "pacman"){
            string a,b;
            cin >> a >> b;
            if(flag) continue;
            if(a == "-R") mp[b] = 0;
            else mp.erase(b);
        }else if(s == "1"){
            string a;cin >> a;
            if(flag) continue;
            if(mp.count(a)){
                if(mp[a] == true) cout << "yes" << endl;
                else cout << "no" << endl;
            }else{
                cout << "no" << endl;
            }
        }else{
            string a;cin >> a;
            if(flag) continue;
            if(mp.count(a)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
