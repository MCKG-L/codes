#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int a[N],b[N];
int n,m;
bool check(int mid){
    int cnt1 = 0,cnt2 = 0;
    // int p1 = lower_bound(a,a+n,mid)-a;
    // if(p1 == n) cnt1 = n;
    // else while(p1 < n && a[p1] == mid) p1 ++;
    // cnt1 = p1;
    // int p2 = lower_bound(b,b+m,mid)-b;
    // cnt2 = m - p2;
    // return cnt1 >= cnt2;
    for(int i=0;i<n;i++){
        if(a[i] <= mid) cnt1 ++;
    }
    for(int i=0;i<m;i++){
        if(b[i] >= mid) cnt2 ++;
    }
    return cnt1 >= cnt2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    // sort(a,a+n);sort(b,b+m);
    long long r = 2e9,l = 0;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}