#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    int sum = 0,x;
    int max_n = 0,min_n = 10;
    for(int i=0;i<n;i++){
        cin >> x;
        max_n = max(max_n,x);
        min_n = min(min_n,x);
        sum += x;
    }
    double ans = (double)(sum - min_n - max_n)/(n-2);
    cout << fixed << setprecision(2) << ans;
    return 0;
}