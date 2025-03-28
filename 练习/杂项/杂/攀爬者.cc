#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
const int N = 5e4 + 5;
struct point{
    int x,y,z;
}a[N];
bool cmp(point p1,point p2){
    return p1.z < p2.z;
}

int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a,a+n,cmp);
    double ans = 0,s;
    for(int i=0;i<n-1;i++){
        s = pow(a[i].x-a[i+1].x,2)+pow(a[i].y-a[i+1].y,2)+pow(a[i].z-a[i+1].z,2);
        ans += sqrt(s);
    }
    cout << fixed << setprecision(3) << ans;
    return 0;
}