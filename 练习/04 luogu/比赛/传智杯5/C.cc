#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;
int size(int n){
    int res = 0;
    if(n == 0) return 1;
    while(n){
        res ++;
        n /= 10;
    }
    return res;
}
void solve(){
    string s = "";
    char c;
    vector<string> alls;
    while(scanf("%c",&c) != EOF){
        if(c == '\n'){
            alls.push_back(s);
            s = "";
        }else{
            s += c;
        }
    }
    int n = alls.size();
    int t = size(n);
    for(int i=0;i<n;i++){
        int k = size(i + 1);
        k = t - k;
        while(k--) cout << ' ';
        cout << i + 1 << ' ' << alls[i] << endl;
    }
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}