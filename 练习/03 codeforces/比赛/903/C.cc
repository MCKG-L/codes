#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int M = 1010;
char a[M][M],b[M][M];
int n;
int find(char a,char b,char c,char d){
    // cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    int aa = a - 'a',bb = b - 'a',cc = c - 'a',dd = d - 'a';
    int M = max(max(aa,bb),max(cc,dd));
    int ans = 0;
    ans += M - aa;
    ans += M - bb;
    ans += M - cc;
    ans += M - dd;
    return ans;
}
void solve(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            // b[j][n-i-1] = a[i][j];

        }
    }
    int ans = 0;int N = n;
    for(int i=0;i<n/2;i++){
        // int N = n - i * 2;
        for(int j=i;j<n-i-1;j++){
            ans += find(a[i][j],a[j][N-i-1],a[N-i-1][N-j-1],a[N-j-1][i]);
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}