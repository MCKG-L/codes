#include <iostream>
#include <vector>
using namespace std;
const int N = 110;
int x,k;
void solve(){
    cin >> x >> k;
    if(x % k != 0){
        cout << 1 << '\n' << x << endl;
        return;
    }
    cout << 2 << endl;
    cout << x - 1 << ' ' << 1 << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}