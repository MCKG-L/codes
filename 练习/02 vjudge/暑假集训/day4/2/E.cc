#include <iostream>
using namespace std;
void solve(){
    long long sum = 0;
    int mn = 1e9;
    int cnt = 0;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x < 0) x = (~x + 1),cnt ++;
        sum += x;
        mn = min(mn,x);
    }
    if(cnt & 1) sum -= mn * 2;
    cout << sum << endl;
}
int main()
{
    int t = 1;cin >> t;
    while(t--) solve();
    return 0;
}