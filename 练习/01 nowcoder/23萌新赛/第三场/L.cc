#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int a[N],b[N];
int n,h;
int main()
{
    cin >> n >> h;
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    sort(a,a+n,[&](int a,int b){return a > b;});
    sort(b,b+n,[&](int a,int b){return a > b;});
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(b[i] < a[0]) break;
        sum += b[i];
        cnt ++;
        if(sum >= h){
            cout << i + 1 << endl;
            return 0;
        }
    }
    int k = h - sum;
    int ans = cnt;
    cout << ans << endl;
    ans += (int)(ceil(k*1.0/a[0]));
    cout << ans << endl;
    return 0;
}