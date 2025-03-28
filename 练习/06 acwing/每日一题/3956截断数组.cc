#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[N];
ll ans,sum,s,n;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i],sum+=a[i];
    if(sum % 3 != 0 || n < 3){
        cout << 0 << endl;
        return 0;
    }
    int mask = sum / 3;
    ll cnt = 0;
    for(int i=1;i<n;i++){
        s += a[i];
        if(s == mask*2) ans += cnt;
        if(s == mask) cnt++;
    }
    cout << ans << endl;
    return 0;
}