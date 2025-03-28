#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    double ans;
    if(n <= 150){
        ans = n * 0.4463;
    }else if(n <= 400){
        ans = 150*0.4463+(n-150)*0.4663;
    }else{
        ans = 150*0.4463+(400-150)*0.4663+(n-400)*0.5663;
    }
    cout << fixed << setprecision(1) << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}