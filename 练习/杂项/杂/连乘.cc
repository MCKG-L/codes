#include <bits/stdc++.h>
using namespace std;
/*
找到因子2和因子5的数目
*/
int main()
{
    int n;cin >> n;
    long long ans = 1,a=0,b=0;
    for(int i=0;i<n;i++){
        int x,t;cin >> x;
        ans *= x;t = x;
        while(x%2==0 && x){
            a++;x/=2;
        }
        while(t%5==0 && t){
            b++;t/=5;
        }
        while(ans >= 100000000000) ans /= 10;
    }
    while(ans >= 1000) ans /= 10;
    cout << ans << endl << min(a,b);
    return 0;
}