#include <iostream>
#include <cmath>
using namespace std;
const int N = 262150;
int a[N],m;
void solve(){
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int s=2;s<=m;s*=2){
        int d = s / 2;
        for(int i=0;i<m/s;i++){
            int k = i * s;
            if(abs(a[k]-a[k+d]) == d){
                if(a[k] == a[k+d] + d){
                    ans ++;
                    a[k] = min(a[k],a[k+d]);
                }
            }else{
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}