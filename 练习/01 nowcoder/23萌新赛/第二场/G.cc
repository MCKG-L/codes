#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n,m;
ll a[N];
bool check(int mid){
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum += max(0LL,a[i]-mid)*2;
    }
    if(sum >= m) return true;
    return false;
}
int main()
{
    cin >> n >> m;
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum * 2 < m){
        cout << -1 << endl;
        return 0;
    }
    int l = 0,r = 1e9;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}