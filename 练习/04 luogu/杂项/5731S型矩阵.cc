#include <iostream>
using namespace std;
const int N = 1001;
int a[N][N];
int main()
{
    int n;cin >> n;
    int k = 1;
    int x = 1,y = 1;
    int dx = -1, dy = 1;
    while(k <= n * n){
        while(x > 0 && y > 0 && x <= n && y <= n){
            a[x][y] = k ++,x += dx,y += dy;
        }
        if(x > n) x --,y += 2;
        if(y > n) y --,x += 2;
        if(x <= 0) x ++;
        if(y <= 0) y ++;
        dx *= -1,dy *= -1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j] << " \n"[j == n];
        }
    }
    return 0;
}