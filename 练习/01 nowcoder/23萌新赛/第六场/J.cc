#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 51;
int c[N][N],s[N][N];
int a[N],b[N];
int n,m;
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            c[i][j] = a[i] * b[j];
            s[i][j] = s[i-1][j] + s[i][j-1] + c[i][j] - s[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
    int x;cin >> x;
    int ans = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int ii=i;ii<=n;ii++){
                for(int jj=j;jj<=m;jj++){
                    int sum = s[ii][jj] - s[ii-1][j] - s[i][jj-1] + s[ii-1][jj-1];
                    if(sum <= x){
                        cout << i << ' ' << j << "-- " << ii << ' ' << jj << endl;
                        cout << sum << endl;
                        ans = max(ans,(ii-i+1)*(jj-j+1));
                        cout << "ans:" << ans << endl;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
