#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    int ans[10] = {};
    for(int i=m;i<=n;i++){
        int x = i;
        while(x!=0){
            ans[x%10]++;
            x /= 10;
        }
    }
    for(int i=0;i<10;i++){
        cout << ans[i] << " \0"[i == 9];
    }
    return 0;
}