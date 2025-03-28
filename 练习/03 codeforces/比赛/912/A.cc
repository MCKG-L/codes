#include <bits/stdc++.h>
using namespace std;
void  solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n == 1 || k >= 2){
        cout << "YES" << endl;
        return;
    }
    bool ok = 1;
    for(int i=1;i<n;i++){
        if(a[i] > a[i+1]) ok = 0;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}