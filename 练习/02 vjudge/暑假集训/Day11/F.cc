#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int a[N],n,c,d;
bool check(int k){

    int ans = 0;
    // for(int i=1;i<=n&&i<=d;i++){
	// 	ans += ((d-i)/(k+1)+1)*a[i];//有重复
    // }
    for(int i=1;i<=d;i++){
        int p = (i-1)%(k+1)+1;
        if(p <= n) ans += a[p];
    }
    if(ans >= c) return 1;
    return 0;
}
void solve(){
    cin >> n >> c >> d;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1,[&](int a,int b){
    	return a > b;
	});
    int sum = 0;
    for(int i=1;i<=n&&i<=d;i++){
        sum += a[i];
    }
    if(sum >= c){
        cout << "Infinity" << endl;
        return;
    }
    int l = 0,r = 1e9;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    if(l == 0){
        if(check(0)) cout << 0 << endl;
        else cout << "Impossible" << endl;
        return;
    }
    cout << l << endl;
}
signed main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}