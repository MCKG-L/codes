#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
void solve(){
    int n;cin >> n;
    int mask = 0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        mask ^= 1;
        if(a[i] > 1) break;
    }
    if(mask) puts("First");
    else  puts("Second");
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}