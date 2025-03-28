#include <iostream>
#include <iomanip>
/*
wa掉了，这个题需要用高精度算法
*/
using namespace std;
double fac(int n){
    double ans = 1;
    while(n!=0){
        ans *= n;
        n--;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    double ans = 0;
    for(int i=1;i<=n;i++){
        ans += fac(i);
    }
    cout << fixed << setprecision(0) << ans;
    return 0;
}