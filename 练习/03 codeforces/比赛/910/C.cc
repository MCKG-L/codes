#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    if(m + n > k + 2 || (k - m - n) % 2){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    string s[2] = {"B","R"};
    int p = 0;
    string mask = s[(m + n) & 1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            if(i >= n - 1 && j == m - 1){
                cout << mask << ' ';
                continue;
            }
            cout << s[j & 1] << ' ';
        }
        cout << endl;
    }
    if(m % 2 == 0) p = 1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            if(i == n - 1 && j == m - 1){
                cout << s[(i & 1 ^ p) ^ 1] << ' ';
                continue;
            }
            cout << s[i & 1 ^ p] << ' ';
        }
        cout << endl;
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