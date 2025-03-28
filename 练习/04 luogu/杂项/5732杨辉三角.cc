#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int a[N][N];
//图形化输出
int main()
{
    int n;cin >> n;
    for(int i=0;i<=n;i++){
        a[i][0] = 0;
        a[i][1] = 1;
    }
    for(int i=1;i<=n;i++){
    	for(int k=1;k<=4*n/2-2*i;k++) cout << " ";
        for(int j=1;j<=i;j++){
            a[i][j] = a[i-1][j] + a[i-1][j-1];
            // cout << a[i][j] << " \n"[j == i];
            printf("%-4d",a[i][j]);
        }
        cout << endl;
    }
    return 0;
}