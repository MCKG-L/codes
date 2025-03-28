#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1e6 + 10;
int a[N];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll sum = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }
    int ans = 0;
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        int l = 1,r = i + 1;
        while(l < r){
            int mid = l + r >> 1;
            if((ll)a[mid] * i > sum) r = mid;
            else l = mid + 1;
        }
        ans = max(ans,i-l+1);
        sum -= a[i];
    }
    cout << ans << endl;
    return 0;
}