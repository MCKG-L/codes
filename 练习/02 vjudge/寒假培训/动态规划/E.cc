#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int mp[N][N],a[N][N],n;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin >> a[i][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            mp[i][j] = max(mp[i+1][j],mp[i+1][j+1]) + a[i][j];
        }
    }
    cout << mp[1][1];
    return 0;
}