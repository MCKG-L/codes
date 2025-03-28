#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n,m;
void solve(){
    cin >> n >> m;
    long long sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum >= m) puts("YES");
    else puts("NO");
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