#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int s1,s2;
int n,c;
int a[N];
int check(int x){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += (a[i] + 2 * x) * (a[i] + 2 * x);
        if(sum > c) return 0;
    }
    return 1;
}
void solve(){
    cin >> n >> c;
    s1 = 0,s2 = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int l = 0,r = 2e9;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}