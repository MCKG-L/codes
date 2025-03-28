#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    long long ans = 0,a = 1,b = 1;
    for(int i=1;i<=n;i++){
        if(i <= 2){
            ans = 1;
            continue;
        }
        ans = a + b;
        a = b;
        b = ans;
    }
    cout << ans << ".00";
    return 0;
}