#include <iostream>
using namespace std;
int main()
{
    int n,m,x;
    cin >> n >> m >> x;
    long long ans = 0;
    for(int i=0;i<n;i++){
        int k;cin >> k;
        if(k >= x) ans ++;
    }
    for(int i=0;i<m;i++){
        int k;cin >> k;
        if(k <= x) ans ++;
    }
    cout << ans << endl;
    return 0;
}