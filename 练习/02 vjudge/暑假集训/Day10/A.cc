#include <iostream>
using namespace std;
int main()
{
    int n,p,q;
    cin >> n >> p >> q;
    int min_n = 1e9;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        min_n = min(min_n,x);
    }
    int ans = min(p,q+min_n);
    cout << ans << endl;
    return 0;
}