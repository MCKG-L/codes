#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
void solve(){
    int k = 2;
    for(int i=0;i<25;i++){
        cout << "? " << 1 << ' ' << k << endl;
        int x;cin >> x;
        if(x == -1){
            cout << "! " << k - 1 << endl;
            return;
        }
        cout << "? " << k << ' ' << 1 << endl;
        int y;cin >> y;
        if(x != y){
            cout << "! " << x + y << endl;
            return;
        }
        k ++;
    }
}
signed main()
{
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
