#include <iostream>
using namespace std;
const int N = 20;
int a[N][N];
int main()
{
    int n;cin >> n;
    int k = 1;
    int x = 1,y = 1;
    while(k <= n * n){
        while(y <= n && !a[x][y]) a[x][y++] = k ++;
        y --,x ++;
        while(x <= n && !a[x][y]) a[x++][y] = k ++;
        x --,y --;
        while(y >= 1 && !a[x][y]) a[x][y--] = k ++;
        y ++,x--;
        while(x >= 1 && !a[x][y]) a[x--][y] = k ++;
        x ++,y ++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j] << " \n"[j == n];
        }
    }
    return 0;
}