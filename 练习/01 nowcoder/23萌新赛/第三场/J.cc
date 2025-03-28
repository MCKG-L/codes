#include <iostream>
using namespace std;
int main()
{
    int ans = 0;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x & 1) ans = max(ans,x);
    }
    cout << ans << endl;
    return 0;
}