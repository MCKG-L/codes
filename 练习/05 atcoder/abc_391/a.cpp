#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 55;
char a[N][N],b[N][N];
void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    for(int i=0;i+m-1<n;i++){
        for(int j=0;j+m-1<n;j++){
            bool ok = 1;
            for(int k=0;k<m;k++){
                for(int k2=0;k2<m;k2++){
                    if(a[i+k][j+k2] != b[k][k2]){
                        ok = 0;break;
                    }
                }
                if(!ok) break;
            }
            if(ok){
                cout << i + 1 << ' ' << j + 1 << endl;
            }
        }
    }
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