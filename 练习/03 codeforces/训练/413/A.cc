#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 210;
int a[N];
void solve(){
    int n,w;
    cin >> n >> w;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int sum = 0,cnt = 0;
    for(int i=n-1;i>=0;i--){
        sum += a[i];
        cnt ++;
        if(sum >= w) break;
    }
    cout << cnt << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}