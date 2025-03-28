#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int N = 5010;
int a[N],n;
void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int sum = 1;
    if(a[0] != 1){
        cout << "NO" << endl;
        return;
    }
    for(int i=1;i<n;i++){
        if(a[i] > sum){
            cout << "NO" << endl;
            return;
        }
        sum += a[i];
    }
    cout << "YES" << endl;
}
signed main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}