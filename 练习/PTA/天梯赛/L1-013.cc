#include <iostream>
using namespace std;
int fac(int n){
    int ans = 1;
    for(int i=2;i<=n;i++){
        ans *= i;
    }
    return ans;
}
int main()
{
    int n;cin >> n;
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans += fac(i);
    }
    cout << ans << endl;
    return 0;
}