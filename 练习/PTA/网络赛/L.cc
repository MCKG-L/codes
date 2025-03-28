#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,T;
    cin >> n >> T;
    int max_ = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        max_ = max(max_,x);
    }
    int ans = (int)(ceil(max_/T));
    if(ans < 2) ans = 2;
    cout << ans << endl;
    return 0;
}