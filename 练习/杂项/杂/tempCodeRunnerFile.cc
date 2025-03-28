#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using ll = long long;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int a[N],n;
void solve(){
    int a,b;
    cin >> a >> b;
    cout << b - a << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}