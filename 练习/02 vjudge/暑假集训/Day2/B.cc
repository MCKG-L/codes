#include <iostream>
using namespace std;
void solve(){
    int s1 = 0,s2 = 0;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x & 1) s2 += x;
        else s1 += x;
    }
    if(s1 > s2) puts("YES");
    else puts("NO");
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}