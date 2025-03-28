#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        int a = n - 1;
        int b = n * (n - 2);
        int gcd = __gcd(a,b);
        cout << a/gcd << ' ' << b/gcd << endl;
    }
    return 0;
}