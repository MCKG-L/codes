#include <iostream>
using namespace std;
typedef unsigned long long ll;
const int N = 1005;
ll s[N][N];
int a[N],b[N];
int n,m,q;
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            s[i][j] = (ll)a[j]*b[i] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
            // s[i][j] = b[i]*a[j];
        }
    }
    cin >> q;
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << s[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    while(q--){
        int sx,sy,fx,fy;
        cin >> sy >> sx >> fy >> fx;
        cout << s[fx][fy] - s[sx-1][fy] - s[fx][sy-1] + s[sx-1][sy-1] << endl;
    }
    return 0;
}