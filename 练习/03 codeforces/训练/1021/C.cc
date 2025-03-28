#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
int n;
bool f1(vector<int> p){
    int l = 1;p[0] = 0;
    //先增加
    if(p[2] < p[1]) return 0;
    while(l <= n && p[l] >= p[l-1]) l ++;
    // cout << "l:" << l << endl;
    for(int i=l+1;i<=n;i++){
        if(p[i] > p[i-1]) return 0;
    }
    // cout << "l" << l << endl;
    int x = (p[1] + p[2]) / 2;
    if(2 * x - p[l] >= p[l-1]){
        cout << x << endl;
        return 1;
    }
    return 0;
}
bool f2(vector<int> p){
    int l = 1;
    p[0] = 1e9;
    //先减少
    if(p[2] > p[1]) return 0;
    while(l <= n && p[l] <= p[l-1]) l ++;
    // cout << "l:" << l << endl;
    for(int i=l+1;i<=n;i++){
        if(p[i] < p[i-1]) return 0;
    }
    int x = (p[1] + p[2] + 1) / 2;
    // cout << "l:" << l << endl;
    if(x * 2 - p[l-1] <= p[l]){
        cout << x << endl;
        return 1;
    }
    return 0;
}
void solve(){
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    int l = 1;a[0] = 0;
    while(l <= n && a[l] >= a[l-1]) l ++;
    if(l == n + 1){
        cout << 0 << endl;
        return;
    }
    /*
    1
    5
    5 3 3 3 5
    */
    l = 0;a[0] = 1e9;
    while(l <= n && a[l] <= a[l-1]) l ++;
    if(l == n + 1){
        cout << 1000000000 << endl;
        return;
    }
    if(f1(a)) return;
    if(f2(a)) return;
    cout << -1 << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}