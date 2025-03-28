#include <iostream>
#include <cmath>
using namespace std;
const int N = 2e5 + 10;
int a[N];
void solve(){
    int n;cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int cnt = 0;
    int min_abs = 1e9;
    for(int i=0;i<n;i++){
        if(a[i] < 0) cnt ++;
        min_abs = min(min_abs,abs(a[i]));
    }
    long long ans = 0;
    if(cnt & 1){
        bool flag = 1;
        // long long ans = 0;
        for(int i=0;i<n;i++){
            if(flag && abs(a[i]) == min_abs){
                ans += -min_abs;
                flag = 0;
            }else{
                if(a[i] > 0) ans += a[i];
                else ans += -a[i];
            }
        }
    }else{
        for(int i=0;i<n;i++){
            ans += abs(a[i]);
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