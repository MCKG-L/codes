#include <iostream>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n;
void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int ans = 0;
    int sum = a[0];
    for(int i=0;i<n;i++){
        sum = sum & a[i];
        if(sum == 0){
            ans ++;
            sum = a[i+1];
        }
    }
    if(ans == 0) ans = 1;
    cout << ans << endl;

}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}