#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int a[N];
void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a[i];
    } 
    sort(a,a+m);
    for(int i=0;i<m;i++){
        cout << a[i] << " \0"[i==m-1];
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}