#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;
void solve(){
    int n,k;
    cin >> n >> k;
    int N = 2010;
    vector<vector<int>> f(N,vector<int>(N)),s(N,vector<int>(N));
    for(int i=0;i<N;i++){
        f[i][0] = 1;
        f[i][i] = 1;
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<i;j++){
            f[i][j] = (f[i-1][j] + f[i-1][j-1]) % k;
        }
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1];
            if(f[i][j] % k == 0 && j <= i) s[i][j] ++;
        }
    }
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        cout << s[a][b] << endl;
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