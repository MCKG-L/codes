#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// char mask[27] = {'A','A'};
char ans[15];
int main()
{
    int m;cin >> m;
    while(m--){
        ll x;cin >> x;
        int cnt = 0;
        while(x){
            int d = x % 26;
            if(d == 0) d = 26;
            ans[++cnt] = 'A' + d - 1;
            x = (x - d)/26;
        }
        while(cnt) cout << ans[cnt--];
        cout << endl;
    }
    
    return 0;
}