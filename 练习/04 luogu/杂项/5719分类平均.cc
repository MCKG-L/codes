#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n,k,x;
    cin >> n >> k;
    int cnt1 = 0,cnt2 = 0;
    double sum1 = 0.0,sum2 = 0.0;
    for(int i=1;i<=n;i++){
        if(i % k == 0){
            sum1 += i;
            cnt1++;
        }else{
            sum2 += i;
            cnt2++;
        }
    }
    double ans1 = sum1 / cnt1;
    double ans2 = sum2 / cnt2;
    cout << fixed << setprecision(1) << ans1 << " " << ans2;
    return 0;
}