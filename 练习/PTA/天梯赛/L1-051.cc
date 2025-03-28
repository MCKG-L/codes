#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n,x;
    cin >> n >> x;
    double ans = n * 1.0*x / 10;
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}