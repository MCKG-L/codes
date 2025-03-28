#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
void solve(){
    int n;
    cin >> n;
    if(n > 1 && n & 1){
        cout << -1 << endl;
        return;
    }
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    cout << n << ' ' << n-1 << ' ';
    int m = 1,M = n - 1;
    for(int i=1;i<n/2;i++){
        cout << n - M + m << ' ';
        M --;
        cout << M - m << ' ';
        m++;
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}