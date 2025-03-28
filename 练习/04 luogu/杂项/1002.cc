#include <iostream>
using namespace std;
const int N = 25;
int fx,fy,mx,my;
bool a[N][N];
long long dp[N][N];
int dx[9] = {0,2,1,-1,-2,-2,-1,1,2};
int dy[9] = {0,1,2,2,1,-1,-2,-2,-1};
int main()
{
    cin >> fx >> fy >> mx >> my;
    fx++,fy++,mx++,my++;
    for(int i=0;i<9;i++){
        int nx = mx + dx[i];
        int ny = my + dy[i];
        if(nx < 0 || ny < 0) continue;
        a[nx][ny] = 1;
    }
    dp[1][1] = 1;
    for(int i=1;i<=fx;i++){
        for(int j=1;j<=fy;j++){
            if(a[i][j] || (i == 1 && j == 1)) continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    cout << dp[fx][fy] << endl;
    return 0;
}