#include <iostream>
using namespace std;
typedef long long ll;
/*
求最大距离的最小值-->二分答案
*/
const int N = 1e5+10;
int a[N];
int L,n,k;
bool check(int L){
    int K = k;
    int t = 0;//距离起点的距离
    for(int i=1;i<n;i++){
        if(K < 0) break;
        if(a[i]-t<=L) t = a[i];
        else{
            t += L;
            i--;
            K--;
        }
    }
    if(K >= 0) return true;
    return false;
}
int main()
{
    cin >> L >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int l = 0,r = L;
    int ans = 0;
    while(l <= r){
        int mid = (ll)l + r >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}