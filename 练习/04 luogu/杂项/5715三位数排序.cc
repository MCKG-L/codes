#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    int maxn = max(a,max(b,c));
    int minn = min(a,min(b,c));
    int mid = a + b + c - minn - maxn;
    cout << minn << " " << mid << " " << maxn;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}