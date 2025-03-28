#include <iostream>
using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    int cnt = 0;
    int s = 1;
    for(int i=1;;i++){
        int j = i;
        while(j <= n){
            cout << j;
            j+=k;
            cnt++;
            // if(cnt != n-1) cout << ' ';
            if(cnt >= n)break;
            cout << ' ';
        }
        if(cnt >= n) break;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}