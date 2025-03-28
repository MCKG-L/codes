#include <iostream>
using namespace std;
int main()
{
    int n,x;
    cin >> n;
    int ans = 1000;
    while(n--){
        cin >> x;
        ans = min(ans,x);
    }
    cout << ans;
    return 0;
}