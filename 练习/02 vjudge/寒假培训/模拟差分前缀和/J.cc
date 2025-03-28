#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
/*
二维差分 二维前缀和
*/
vector<vector<int>> a(N,vector<int>(N));
int main()
{
    int x1,y1,x2,y2;
    int n, m;
    cin >> n >> m;
   //将a数组看作答案数组的差分数组，将循环累加转化为单点操作
    for(int i=1;i<=m;i++){
        cin>>x1>>y1>>x2>>y2;
        a[x2+1][y2+1]++;
        a[x2+1][y1]--;
        a[x1][y2+1]--;
        a[x1][y1]++;
    }
    //差分数组求前缀和得到答案数组
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j] = a[i-1][j]+a[i][j-1]+a[i][j]-a[i-1][j-1];
            cout << a[i][j] << " \n"[j == n];
        }
    }
    return 0;
}