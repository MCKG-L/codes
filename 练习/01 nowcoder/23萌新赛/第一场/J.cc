#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int N = 1010;
int a[N];
int main()
{
    int n;cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a,a+n);
    double min_n = (1.0*sum - a[n-1])/(n-1);
    double max_n = (1.0*sum - a[0])/(n-1);
    cout << fixed << setprecision(6);
    cout << min_n << ' ' << max_n << endl;
    return 0;
}