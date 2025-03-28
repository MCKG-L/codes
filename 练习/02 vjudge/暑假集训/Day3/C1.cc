#include <iostream>
using namespace std;
int main()
{
    int t = 0;cin >> t;
    while(t--){
        long long n,ans = 0;
        cin >> n;
        while(n){
            ans += n;
            n /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}