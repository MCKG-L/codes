#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,m;cin >> n >> m;
        long long ans = 0;
        for(int i=1;i<=n;i++){
            ans += i*i;
        }
        cout << ans * m << endl;
    }
    return 0;
}