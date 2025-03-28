#include <iostream>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int n;
int a[N];
void solve(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = 0;
    int mask = 0;
    for(int i=n-1;i>0;i--){
        if(!mask && a[i] < a[i-1]) continue;
        if(a[i] == a[i-1]) continue;
        if(a[i] > a[i-1]) mask = 1;
        if(mask && a[i] < a[i-1]){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}