#include <iostream>
using namespace std;
const int N = 310;
int ans[N][N];
void solve(){
    int n,m;
    cin >> n >> m;
    bool mask = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;cin >> x;
            int s = (i > 0) + (i < n - 1) + (j > 0) + (j < m - 1);
            if(s >= x) ans[i][j] = s;
            else{
                mask = 0;
            }
        }
    }
    if(mask){
        cout << "YES" << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
    }else{
        cout << "NO" << endl;
    }
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}