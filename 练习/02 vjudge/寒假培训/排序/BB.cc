#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
int a[N];
void solve(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    nth_element(a,a+k,a+n);
    cout << a[k];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
