#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    if(n > m + k){
        cout << 2 * (m + k) + 1 << endl;
    }else{
        cout << 2 * n - 1 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}