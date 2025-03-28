#include <iostream>
using namespace std;
const int N = 1005;
int a[N][N];
int main()
{
    int n,m;cin >> n >> m;
    while(m--){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++;
        a[x2+1][y2+1]++;
        a[x2+1][y1]--;
        a[x1][y2+1]--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            cout << a[i][j] << " \n"[j == n];
        }
    }
    return 0;
}