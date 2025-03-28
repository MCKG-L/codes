#include <iostream>
using namespace std;
int main()
{
    int t;cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        int s = a + b + c;
        int ma = max(a,max(b,c));
        int mi = min(a,min(b,c));
        int ans = s - ma - mi;
        cout << ans << endl;
    }
    return 0;
}