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
void solve(){
    string s;cin >> s;
    int p = -1;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>=5){
            int j = i - 1;
            while(s[j] == '4') j --;
            p = j + 1;break;
        }
    }
    if(p == 0){
        cout << 1;
        for(int i=0;i<s.size();i++){
            cout << 0;
        }
        cout << endl;
    }else if(p == -1){
        cout << s << endl;
    }else{
        for(int i=0;i<s.size();i++){
            if(i < p-1)cout << s[i];
            else if(i == p-1) cout << s[i]-'0'+1;
            else cout << 0;
        }
        cout << endl;
    }
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    int a = 0;cout << -a << endl;
    while(t--) solve();
    return 0;
}
