#include <iostream>
// #include <limits.h>
using namespace std;
const int N = 1e3 + 5;
int a[N][N];
int main()
{
    int n,m,c;
    cin >> n >> m >> c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    int ans = -1e9;
    int x,y;
    for(int i=1;i<=n-c+1;i++){
        for(int j=1;j<=m-c+1;j++){
            // int sum = a[i+c-1][j+c-1] + a[i+c-2][j+c-1] + a[i+c-1][j+c-2] - a[i][j];
            int sum = a[i+c-1][j+c-1] - a[i+c-1][j-1] - a[i-1][j+c-1] + a[i-1][j-1];
            if(sum > ans){
                x = i;y = j;
                ans = sum;
            }
        }
    }
    cout << x << " " << y;
    return 0;
}