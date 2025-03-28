#include <bits/stdc++.h>
using namespace std;
void  solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) a[i] = (1 << 30) - 1;
    vector<vector<int>> m(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> m[i][j];
            if(i != j) a[i] &= m[i][j];
        }
    }
    bool ok = 1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if((a[i] | a[j]) != m[i][j]){
                ok = 0;
                break;
            }
        }
        if(ok == 0) break;
    }
    if(ok){
        cout << "YES" << endl;
        for(int i=1;i<=n;i++) cout << a[i] << ' ';
        cout << endl;
    }else{
        cout << "NO" << endl;
    }
}
int main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}