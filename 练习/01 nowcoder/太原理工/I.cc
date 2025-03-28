#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll a[N];
ll n,x;
int main()
{
    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int i=0,j=0;
    ll s = 1;
    int ans = 1e9 + 10;
    while(i < n && j < n){
        while(j < n && s < x){
            s *= a[j];j++;
        }
        while(i < j && s >= x){
            ans = min(ans,j-i);
            s /= a[i];
            i++;
        }
    }
    if(ans == 1e9 + 10) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}