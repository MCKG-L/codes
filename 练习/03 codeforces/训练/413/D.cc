#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll inv[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        ll ans = 1,p;
        cin >> p;
        inv[1] = 1;
        // for(int i=2;i<p;i++) inv[i] = (p-p/i)*inv[p%i]%p,ans += inv[i];
        cout << (p * (p-1) >> 1) << '\n';
    }
    return 0;
}