#include <iostream>
#include <cmath>
using namespace  std;
const int sa = 100,sb = 100;
int main()
{
    int x,y;cin >> x >> y;
    double s = x * y / 2.0 + y * (100-x) + (100-y)*(100-x)/2.0;
    double ans = sa * sb / 2 - s;
    cout << ans << endl;
    return 0;
}