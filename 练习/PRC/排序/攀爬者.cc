#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
struct p{
    int x,y,z;
}a[N];
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a,a+n,[&](p p1,p p2){return p1.z < p2.z;});
    double ans = 0.0,s;
    for(int i=0;i<n-1;i++){
        s = pow(a[i+1].x-a[i].x,2)+pow(a[i+1].y-a[i].y,2)+pow(a[i+1].z-a[i].z,2);
        ans += sqrt(s);
    }
    cout << fixed << setprecision(3) << ans;
    return 0;
}