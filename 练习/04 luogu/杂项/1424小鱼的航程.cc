#include <bits/stdc++.h>
using namespace std;
void solve(){
    int x,n;
    cin >> x >> n;
    int ans = 0;
    for(int i=0;i<n;i++){
        if((x+i)%7==0||(x+i)%7==6) continue;
        else ans++;
    }
    cout << ans * 250;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}