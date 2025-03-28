#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
const int N = 110;
int n,m;
bool mask;
void func(int x){
    if(x > n) return;
    if(x == n){
        mask = 1;
        return;
    }
    func(x*3);
    if(x % 2 == 0) func(x/2*3);
}
void solve(){
    cin >> n >> m;
    mask = 0;
    func(m);
    if(mask) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}